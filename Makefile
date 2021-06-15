CC = g++
FLAGS = -std=c++14 -Wall -g
OBJS = CardDeck.o

all: hw02

hw02: hw02.cpp CardDeck.o
	$(CC) $(FLAGS) hw02.cpp -o hw02 $(OBJS)

CardDeck.o: CardDeck.cpp CardDeck.h
	$(CC) $(FLAGS) -c CardDeck.cpp -o CardDeck.o

clean:
	rm *.o hw02 hw02.tar hw02.scr

tar:
	tar cf hw02.tar hw02.scr Makefile hw02.cpp CardDeck.h CardDeck.cpp
