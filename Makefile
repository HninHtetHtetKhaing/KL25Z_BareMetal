# KL25Z Bare-Metal Makefile
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m0plus -O1 -Wall -Iinclude
LDFLAGS = -T kl25z_linker.ld -nostdlib

SRCS = src/main.c src/wdog.c
OBJS = $(SRCS:.c=.o)
TARGET = firmware.elf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

flash: $(TARGET)
	pyocd flash $(TARGET) --target kl25z
