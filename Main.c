// #include "PullPointSubscriptionBinding.nsmap" // XML namespace mapping table (only needed once at the global level)
// #include "soapH.h"                            // server stubs, serializers, etc.

// int main()
// {
//   fprintf(stdout,"Starting...\n");
//   struct soap *soap_srv = soap_new1(SOAP_XML_INDENT);
//   if (!soap_valid_socket(soap_bind(soap_srv, NULL, 8080, 10))) // port 8080 and small BACKLOG queue for iterative servers
//     exit(EXIT_FAILURE);
//   while (soap_valid_socket(soap_accept(soap_srv)))
//   {
//     if (soap_serve(soap_srv) != SOAP_OK)
//       break;
//     soap_destroy(soap_srv); // delete deserialized C++ instances
//     soap_end(soap_srv);     // delete other managed data
//   }
//   soap_print_fault(soap_srv, stderr);
//   soap_free(soap_srv); // free the soap struct context data
// }
#include "PullPointSubscriptionBinding.nsmap" // XML namespace mapping table (only needed once at the global level)
#include "soapH.h"
#include "plugin/threads.h"

#define PORTNUM 8080
#define BACKLOG 10

void * accept_request(struct soap*);
void * process_request(struct soap*);
void cleanup(struct soap*);

int main()
{
  struct soap *soap = soap_new();
  soap->bind_flags = SO_REUSEADDR; // immediate port reuse
  soap->accept_timeout = 3600;     // exit loop when no request arrives in one hour
  soap->send_timeout = 5;          // 5 seconds max socket stall time (unlimited by default)
  soap->recv_timeout = 5;
  soap->transfer_timeout = 30;    // 30 seconds max message transfer time (unlimited by default)
  soap->recv_maxlength = 1048576; // limit messages received to 1MB (2GB by default)
  if (soap_valid_socket(soap_bind(soap, NULL, PORTNUM, BACKLOG)))
  {
    while (1)
    {
      if (soap_valid_socket(soap_accept(soap)))
      {
        THREAD_TYPE tid;
        struct soap *tsoap = soap_copy(soap);
        if (!tsoap)
          soap_force_closesock(soap);
        else
          while (THREAD_CREATE(&tid, (void *(*)(void *))&accept_request, (void *)tsoap))
            sleep(1); // failed, try again
      }
      else if (soap->errnum) // accept failed, try again after 1 second
      {
        soap_print_fault(soap, stderr);
        sleep(1);
      }
      else // accept_timeout timed out, quit looping
      {
        break;
      }
      soap_destroy(soap);
      soap_end(soap);
    }
  }
  soap_free(soap);
}
void *accept_request(struct soap *soap)
{
  THREAD_TYPE tid;
  struct soap *tsoap;
  THREAD_DETACH(THREAD_ID);
  // create a new thread that is timed to execute for max 10 seconds
  tsoap = soap_copy(soap);
  if (!tsoap)
  {
    soap_force_closesock(soap);
  }
  else
  {
    while (THREAD_CREATE(&tid, (void *(*)(void *))&process_request, (void *)tsoap))
      sleep(1); // failed, try again
    // allow serving the request by the new thread for up to 30 seconds max
    sleep(30);
    // terminate process_request thread
    THREAD_CANCEL(tid);
  }
  // clean up
  soap_destroy(soap);
  soap_end(soap);
  soap_free(soap);
  return NULL;
}
void *process_request(struct soap *soap)
{
  fprintf(stdout, "Processing...\n");
  // add the cleanup function
  pthread_cleanup_push((void (*)(void *))&cleanup, (void *)soap);
  soap_serve(soap);
  // remove the cleanup function and call it to cleanup the context
  pthread_cleanup_pop(1);
  return NULL;
}
void cleanup(struct soap *soap)
{
  soap_destroy(soap);
  soap_end(soap);
  soap_free(soap);
}