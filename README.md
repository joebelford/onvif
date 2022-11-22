# ONVIF testing

## Notes for gsoap

### Start container

Execute `docker run -it -v $PWD:/build/onvif_specs gsoap bash`

### Building header

Execute `wsdl2h https://www.onvif.org/ver10/events/wsdl/event.wsdl`

## Building source files

Execute `soapcpp2 event.h`