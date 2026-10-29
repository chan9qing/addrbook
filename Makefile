CC      = gcc
CFLAGS  = -Wall -g -MMD -MP -Iinclude
TARGET  = build/addrbook

SRCS    = $(wildcard src/*.c)
OBJS    = $(patsubst src/%.c,build/%.o,$(SRCS))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

-include $(OBJS:.o=.d)

run: $(TARGET)
	./$(TARGET)

clean:
	del /q build
