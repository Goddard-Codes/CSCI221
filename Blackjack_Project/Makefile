#Author: Evan Goddard
#Date: 12/15/2025
CC = g++
CFLAGS = -Wall -std=c++14

final_main: final_main.o deck.o card.o node.o queue.o hand.o
	$(CC) $(CFLAGS) final_main.o deck.o card.o queue.o node.o hand.o -o final_main

final_main.o:  final_main.cpp deck.hpp hand.hpp
	$(CC) $(CFLAGS) -c final_main.cpp

deck.o:	deck.cpp deck.hpp card.hpp
	$(CC) $(CFLAGS) -c deck.cpp
card.o: card.cpp card.hpp
	$(CC) $(CFLAGS) -c card.cpp

queue.o: queue.cpp queue.hpp node.hpp
	$(CC) $(CFLAGS) -c queue.cpp
node.o: node.cpp node.hpp
	$(CC) $(CFLAGS) -c node.cpp
hand.o: hand.cpp hand.hpp
	$(CC) $(CFLAGS) -c hand.cpp

clean:
	rm -f *.o final_main