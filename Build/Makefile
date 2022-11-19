CC := clang
OUTPUT_DIR := bin
GSOAP_DIR := /opt/gsoap-2.8
SRC := Main.c soapC.c soapServer.c soapClient.c soapStub.c $(GSOAP_DIR)/gsoap/stdsoap2.c
APP := notify
LDFLAGS_Linux := -lssl -lz -lcrypto
CFLAGS_GSoap := -I$(GSOAP_DIR)
CFLAGS_GSoap += -I$(GSOAP_DIR)/gsoap
CFLAGS_GSoap += -I$(GSOAP_DIR)/gsoap/plugins
CFLAGS_GSoap += -I$(GSOAP_DIR)/gsoap/import
CFLAGS_CONFIG_H := -DHAVE_CONFIG_H

CFLAGS := $(CFLAGS_GSoap) $(CFLAGS_CONFIG_H)

CFLAGS_DEBUG := -DDEBUG_STAMP

info:
	@echo "make -f Build/Makefile notify"
clean:
	rm -rf $(OUTPUT_DIR)/*
notify:
	$(CC) -o $(OUTPUT_DIR)/$(APP) $(SRC) $(CFLAGS) $(LDFLAGS_Linux)
debug:
	$(CC) -o $(OUTPUT_DIR)/$(APP)-debug $(SRC) $(CFLAGS_DEBUG) $(CFLAGS) $(LDFLAGS_Linux)
