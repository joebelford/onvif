#include "PullPointSubscriptionBinding.nsmap" // XML namespace mapping table (only needed once at the global level)
#include "soapH.h"                            // server stubs, serializers, etc.

int main()
{
  fprintf(stdout,"Starting...\n");
  struct soap *soap_srv = soap_new1(SOAP_XML_INDENT);
  if (!soap_valid_socket(soap_bind(soap_srv, NULL, 8080, 10))) // port 8080 and small BACKLOG queue for iterative servers
    exit(EXIT_FAILURE);
  while (soap_valid_socket(soap_accept(soap_srv)))
  {
    if (soap_serve(soap_srv) != SOAP_OK)
      break;
    soap_destroy(soap_srv); // delete deserialized C++ instances
    soap_end(soap_srv);     // delete other managed data
  }
  soap_print_fault(soap_srv, stderr);
  soap_free(soap_srv); // free the soap struct context data
}