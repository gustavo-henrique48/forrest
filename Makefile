CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -O2
INCLUDES = -Iinclude

PKG = raylib
LIBS = $(shell pkg-config --libs $(PKG))
CFLAGS += $(shell pkg-config --cflags $(PKG))

SRC = $(wildcard src/*.c)

BUILD_DIR = build
OUT = $(BUILD_DIR)/forest

all: $(OUT)

$(OUT): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CC) $(SRC) $(CFLAGS) $(INCLUDES) -o $(OUT) $(LIBS)

run: all
	./$(OUT)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
