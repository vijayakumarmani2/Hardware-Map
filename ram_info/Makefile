# Variables
CC = gcc
CFLAGS = -Wall -Wextra
TARGET = RAM_info_own
PREFIX = /usr/local

# Default target
all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

install: $(TARGET)
	install -m 755 $(TARGET) $(PREFIX)/bin/

uninstall:
	rm -f $(PREFIX)/bin/$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all install uninstall clean

