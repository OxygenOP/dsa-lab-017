# Makefile

CXX = g++
CXXFLAGS = -Wall

all: server

server: main.cpp server.cpp queue.cpp
	$(CXX) $(CXXFLAGS) main.cpp server.cpp queue.cpp -o server

run: server
	./server

clean:
	rm -f server
