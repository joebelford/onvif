CC := clang
OUTPUT_DIR := bin
GSOAP_DIR := /opt/gsoap-2.8
SRC := Main.c soapC.c soapServer.c soapClient.c soapStub.c $(GSOAP_DIR)/gsoap/stdsoap2.c
APP := notify
LDFLAGS_Linux := -lssl -lz -lcrypto
CFLAGS_GSOAP := -I$(GSOAP_DIR)
CFLAGS_GSOAP += -I$(GSOAP_DIR)/gsoap
CFLAGS_CONFIG_H := -DHAVE_CONFIG_H

CFLAGS_STANDARD := -DWITH_OPENSSL -DWITH_DOM -DWITH_GZIP

CFLAGS := $(CFLAGS_GSOAP) $(CFLAGS_CONFIG_H) $(CFLAGS_STANDARD)

CFLAGS_DEBUG := -DDEBUG_STAMP

info:
	@echo "make -f Build/Makefile notify"
clean:
	rm -rf $(OUTPUT_DIR)/*
notify:
	$(CC) -o $(OUTPUT_DIR)/$(APP) $(SRC) $(CFLAGS) $(LDFLAGS_Linux)
debug:
	$(CC) -o $(OUTPUT_DIR)/$(APP)-debug $(SRC) $(CFLAGS_DEBUG) $(CFLAGS) $(LDFLAGS_Linux)
