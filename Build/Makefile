CC := clang
OUTPUT_DIR := bin
SRC := Main.c soapC.c soapServer.c soapStub.c
APP := notify
LDFLAGS_Linux := -lgsoapssl -lssl -lz -lcrypto
# DEBUG := -DDEBUG
info:
	@echo "Run make notify"
clean:
	rm -rf $(OUTPUT_DIR)/*
notify:
	$(CC) -o $(OUTPUT_DIR)/$(APP) $(SRC) $(LDFLAGS_Linux)
# debug:
# 	@$(notify) $(DEBUG)
