CC = g++
CFLAGS = $(shell curl-config --cflags)
LIBS = $(shell curl-config --libs)

simple_get: simple_get.cpp
	$(CC) $(CFLAGS) simple_get.cpp -o simple_get $(LIBS)

# Connect with https to avoid HTTP 301
test_simple_get: simple_get
	./simple_get https://www.example.org

BIN = simple_get 

.PHONY: all clean test

all: simple_get

test: test_simple_get

clean:
	rm $(BIN)