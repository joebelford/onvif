#include "PullPointSubscriptionBinding.nsmap" // XML namespace mapping table (only needed once at the global level)
#include "soapH.h"
#include "plugin/threads.h"

#define BACKLOG (100) // Max request backlog of pending requests
int main(int argc, char **argv) 
{
  struct soap soap; 
  soap_init(&soap); 
  if (argc < 2) // no args: assume this is a CGI application 
  {
    soap_serve(&soap);   // serve request, one thread, CGI style 
    soap_destroy(&soap); // delete managed class instances 
    soap_end(&soap);     // delete managed data and temporaries 
  } 
  else 
  {
    void *process_request(void*); 
    struct soap *tsoap; 
    THREAD_TYPE tid; 
    int port = atoi(argv[1]); // first command-line arg is port 
    SOAP_SOCKET m, s; 
    soap.send_timeout = 10; // 10 seconds max socket delay 
    soap.recv_timeout = 10; // 10 seconds max socket delay 
    soap.accept_timeout = 3600; // server stops after 1 hour of inactivity 
    soap.max_keep_alive = 100; // max keep-alive sequence 
    m = soap_bind(&soap, NULL, port, BACKLOG); 
    if (!soap_valid_socket(m)) 
      exit(EXIT_FAILURE); 
    fprintf(stderr, "Socket connection successful %d\n", m); 
    while (1)
    {
      s = soap_accept(&soap); 
      if (soap_valid_socket(s)) 
      {
        fprintf(stderr, "Accept socket %d connection from IP %d.%d.%d.%d\n", s, (soap.ip>>24)&0xFF, (soap.ip>>16)&0xFF, (soap.ip>>8)&0xFF, soap.ip&0xFF); 
        tsoap = soap_copy(&soap); // make a copy 
        if (!tsoap) 
          soap_force_closesock(&soap);
        else
          while (THREAD_CREATE(&tid, (void*(*)(void*))process_request, (void*)tsoap))
            sleep(1); // failed, try again
      }
      else if (soap.errnum) // accept failed, try again after 1 second
      {
        soap_print_fault(&soap, stderr); 
        sleep(1);
      } 
      else
      {
        fprintf(stderr, "server timed out\n"); 
        break; 
      } 
    } 
  } 
  soap_done(&soap); // finalize context
  return 0; 
} 
void *process_request(void* tsoap) 
{
  struct soap *soap = (struct soap*)tsoap;
  THREAD_DETACH(THREAD_ID); 
  soap_serve(soap); 
  soap_destroy(soap); // delete managed class instances 
  soap_end(soap);     // delete managed data and temporaries 
  soap_free(soap);    // finalize and delete the context
  return NULL; 
}
