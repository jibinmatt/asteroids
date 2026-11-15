CC = gcc
PKG_CONFIG ?= pkg-config

TARGET = build/asteroids.exe
SOURCES = src/main.c src/asteroid.c src/spaceship.c
OBJECTS = $(SOURCES:src/%.c=build/%.o)
DEPFILES = $(OBJECTS:.o=.d)

CPPFLAGS += -Iinclude $(shell $(PKG_CONFIG) --cflags sdl3)
CFLAGS += -std=c17 -Wall -Wextra -Wpedantic -g
LDLIBS += $(shell $(PKG_CONFIG) --libs sdl3)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
		$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

build/%.o: src/%.c | build
		$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

build:
		if not exist $@ mkdir $@

-include $(DEPFILES)

clean:
		if exist build rmdir /s /q build