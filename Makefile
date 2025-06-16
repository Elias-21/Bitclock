CC = gcc
CFLAGS = 
SRC = src
BUILD = build
WAYBAR_CONF_DIR = $(HOME)/.config/waybar


# Compile and Link everything
all:
	mkdir -v $(BUILD)
	$(CC) $(CFLAGS) -c $(SRC)/main.c -o $(BUILD)/main.o
	$(CC) $(CFLAGS) -c $(SRC)/requests.c -o $(BUILD)/requests.o
	$(CC) $(CFLAGS) -c $(SRC)/height.c -o $(BUILD)/height.o
	$(CC) $(CFLAGS) -c $(SRC)/balance.c -o $(BUILD)/balance.o
	$(CC) $(CFLAGS) -lcurl -ljson-c -o bitclock $(BUILD)/main.o $(BUILD)/requests.o $(BUILD)/height.o $(BUILD)/balance.o


#  Installs everything but keeps the user config if its there
install:
	mkdir -pv $(WAYBAR_CONF_DIR)
	cp bitclock $(WAYBAR_CONF_DIR)
	sh waybar/install.sh


#  Installs everything and replaces the user waybar config witth the example waybar config
install-replace-config:
	rm -rf $(WAYBAR_CONF_DIR)
	mkdir -pv $(WAYBAR_CONF_DIR)
	cp bitclock $(WAYBAR_CONF_DIR)
	sh waybar/install.sh


# Removes the build directory
clean:
	rm -rf build
