CC ?= $(CROSS_COMPILE)gcc
CFLAGS ?= -Wall -Wextra -g
TARGET = aesdsocket
SRCS = aesdsocket.c

.PHONY: all default clean

all: $(TARGET)

default: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) *.o
