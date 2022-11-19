CC := clang
OUTPUT_DIR := bin
SRC := Main.c soapC.c soapServer.c soapStub.c stdsoap2.c
APP := notify
LDFLAGS_Linux := -lssl -lz -lcrypto
GSOAP_DIR := /opt/gsoap-2.8
CFLAGS_Gsoap := -I$(GSOAP_DIR)
CFLAGS_GSoap += -I$(GSOAP_DIR)/gsoap
CFLAGS_GSoap += -I$(GSOAP_DIR)/gsoap/plugins
CFLAGS_GSoap += -I$(GSOAP_DIR)/gsoap/import

CFLAGS_DEBUG := -DDEBUG_STAMP
info:
	@echo "make -f Build/Makefile notify"
clean:
	rm -rf $(OUTPUT_DIR)/*
notify:
	$(CC) -o $(OUTPUT_DIR)/$(APP) $(SRC) $(CFLAGS_GSoap) $(LDFLAGS_Linux)
debug:
	$(CC) -o $(OUTPUT_DIR)/$(APP)-debug $(SRC) $(CFLAGS_DEBUG) $(CFLAGS_GSoap) $(LDFLAGS_Linux)
