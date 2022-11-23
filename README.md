# ONVIF testing

## Notes for gsoap

### Start container

Execute `docker run -it -v $PWD:/build/onvif_specs gsoap bash`

### Building header

Execute `wsdl2h -c -L -g -o event.h https://www.onvif.org/ver10/events/wsdl/event.wsdl https://www.onvif.org/ver10/device/wsdl/devicemgmt.wsdl https://www.onvif.org/ver10/schema/onvif.xsd https://www.onvif.org/ver10/schema/common.xsd`

## Building source files

Execute `soapcpp2 -c -r event.h`