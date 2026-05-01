# My makefile for Assignment 02 (Counting)

calc: main.o count.o
	g++ -o calc main.o count.o

main.o: main.cpp
	g++ -c main.cpp

count.o: count.cpp count.h
	g++ -c count.cpp

clean:
	rm -f calc *.o *~
