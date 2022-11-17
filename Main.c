#include "PullPointSubscriptionBinding.nsmap" // XML namespace mapping table (only needed once at the global level)
#include "soapH.h"                            // server stubs, serializers, etc.

/******************************************************************************\
 *                                                                            *
 * Server-Side Operations                                                     *
 *                                                                            *
\******************************************************************************/

/** Web service one-way operation 'SOAP_ENV__Fault' implementation, should return value of soap_send_empty_response() to send HTTP Accept acknowledgment, or return an error code, or return SOAP_OK to immediately return without sending an HTTP response message */
SOAP_FMAC5 int SOAP_FMAC6 SOAP_ENV__Fault(struct soap *ctx, char *faultcode, char *faultstring, char *faultactor, struct SOAP_ENV__Detail *detail, struct SOAP_ENV__Code *SOAP_ENV__Code, struct SOAP_ENV__Reason *SOAP_ENV__Reason, char *SOAP_ENV__Node, char *SOAP_ENV__Role, struct SOAP_ENV__Detail *SOAP_ENV__Detail)
{
  return SOAP_OK;
};
/** Web service operation '__tev__PullMessages' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__PullMessages(struct soap *ctx, struct _tev__PullMessages *tev__PullMessages, struct _tev__PullMessagesResponse *tev__PullMessagesResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__Seek' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Seek(struct soap *ctx, struct _tev__Seek *tev__Seek, struct _tev__SeekResponse *tev__SeekResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__SetSynchronizationPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__SetSynchronizationPoint(struct soap *ctx, struct _tev__SetSynchronizationPoint *tev__SetSynchronizationPoint, struct _tev__SetSynchronizationPointResponse *tev__SetSynchronizationPointResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__Unsubscribe' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Unsubscribe(struct soap *ctx, struct _wsnt__Unsubscribe *wsnt__Unsubscribe, struct _wsnt__UnsubscribeResponse *wsnt__UnsubscribeResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__GetServiceCapabilities(struct soap *ctx, struct _tev__GetServiceCapabilities *tev__GetServiceCapabilities, struct _tev__GetServiceCapabilitiesResponse *tev__GetServiceCapabilitiesResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__CreatePullPointSubscription' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__CreatePullPointSubscription(struct soap *ctx, struct _tev__CreatePullPointSubscription *tev__CreatePullPointSubscription, struct _tev__CreatePullPointSubscriptionResponse *tev__CreatePullPointSubscriptionResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__GetEventProperties' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__GetEventProperties(struct soap *ctx, struct _tev__GetEventProperties *tev__GetEventProperties, struct _tev__GetEventPropertiesResponse *tev__GetEventPropertiesResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__AddEventBroker' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__AddEventBroker(struct soap *ctx, struct _tev__AddEventBroker *tev__AddEventBroker, struct _tev__AddEventBrokerResponse *tev__AddEventBrokerResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__DeleteEventBroker' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__DeleteEventBroker(struct soap *ctx, struct _tev__DeleteEventBroker *tev__DeleteEventBroker, struct _tev__DeleteEventBrokerResponse *tev__DeleteEventBrokerResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__GetEventBrokers' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__GetEventBrokers(struct soap *ctx, struct _tev__GetEventBrokers *tev__GetEventBrokers, struct _tev__GetEventBrokersResponse *tev__GetEventBrokersResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__Renew' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Renew(struct soap *ctx, struct _wsnt__Renew *wsnt__Renew, struct _wsnt__RenewResponse *wsnt__RenewResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__Unsubscribe_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Unsubscribe_(struct soap *ctx, struct _wsnt__Unsubscribe *wsnt__Unsubscribe, struct _wsnt__UnsubscribeResponse *wsnt__UnsubscribeResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__Subscribe' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Subscribe(struct soap *ctx, struct _wsnt__Subscribe *wsnt__Subscribe, struct _wsnt__SubscribeResponse *wsnt__SubscribeResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__GetCurrentMessage' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__GetCurrentMessage(struct soap *ctx, struct _wsnt__GetCurrentMessage *wsnt__GetCurrentMessage, struct _wsnt__GetCurrentMessageResponse *wsnt__GetCurrentMessageResponse)
{
  return SOAP_OK;
};
/** Web service one-way operation '__tev__Notify' implementation, should return value of soap_send_empty_response() to send HTTP Accept acknowledgment, or return an error code, or return SOAP_OK to immediately return without sending an HTTP response message */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Notify(struct soap *ctx, struct _wsnt__Notify *wsnt__Notify)
{
  return SOAP_OK;
};
/** Web service operation '__tev__GetMessages' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__GetMessages(struct soap *ctx, struct _wsnt__GetMessages *wsnt__GetMessages, struct _wsnt__GetMessagesResponse *wsnt__GetMessagesResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__DestroyPullPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__DestroyPullPoint(struct soap *ctx, struct _wsnt__DestroyPullPoint *wsnt__DestroyPullPoint, struct _wsnt__DestroyPullPointResponse *wsnt__DestroyPullPointResponse)
{
  return SOAP_OK;
};
/** Web service one-way operation '__tev__Notify_' implementation, should return value of soap_send_empty_response() to send HTTP Accept acknowledgment, or return an error code, or return SOAP_OK to immediately return without sending an HTTP response message */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Notify_(struct soap *ctx, struct _wsnt__Notify *wsnt__Notify)
{
  return SOAP_OK;
};
/** Web service operation '__tev__CreatePullPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__CreatePullPoint(struct soap *ctx, struct _wsnt__CreatePullPoint *wsnt__CreatePullPoint, struct _wsnt__CreatePullPointResponse *wsnt__CreatePullPointResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__Renew_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Renew_(struct soap *ctx, struct _wsnt__Renew *wsnt__Renew, struct _wsnt__RenewResponse *wsnt__RenewResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__Unsubscribe__' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Unsubscribe__(struct soap *ctx, struct _wsnt__Unsubscribe *wsnt__Unsubscribe, struct _wsnt__UnsubscribeResponse *wsnt__UnsubscribeResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__PauseSubscription' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__PauseSubscription(struct soap *ctx, struct _wsnt__PauseSubscription *wsnt__PauseSubscription, struct _wsnt__PauseSubscriptionResponse *wsnt__PauseSubscriptionResponse)
{
  return SOAP_OK;
};
/** Web service operation '__tev__ResumeSubscription' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__ResumeSubscription(struct soap *ctx, struct _wsnt__ResumeSubscription *wsnt__ResumeSubscription, struct _wsnt__ResumeSubscriptionResponse *wsnt__ResumeSubscriptionResponse)
{
  return SOAP_OK;
};

int main()
{
  struct soap *soap = soap_new1(SOAP_XML_INDENT);
  if (!soap_valid_socket(soap_bind(soap, NULL, 8080, 10))) // port 8080 and small BACKLOG queue for iterative servers
    exit(EXIT_FAILURE);
  while (soap_valid_socket(soap_accept(soap)))
  {
    if (soap_serve(soap) != SOAP_OK)
      break;
    soap_destroy(soap); // delete deserialized C++ instances
    soap_end(soap);     // delete other managed data
  }
  soap_print_fault(soap, stderr);
  soap_free(soap); // free the soap struct context data
}