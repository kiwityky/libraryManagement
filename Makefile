CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -O2
INCLUDES=-Iapp -Iapp/core -Iapp/data -Iapp/helpers
SRCS=$(filter-out app/main.c,$(wildcard app/*.c)) $(wildcard app/core/*.c) $(wildcard app/data/*.c) $(wildcard app/helpers/*.c)
OBJS=$(SRCS:.c=.o)
TARGET=library_refactored

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
