CC=g++
SRCDIR=src
BINDIR=bin

all: pong

pong: Ball.o Game.o main.o Player.o
	$(CC) Ball.o Game.o main.o Player.o -o pong -lsfml-graphics -lsfml-window -lsfml-system

Ball.o: Ball.cc Ball.h
	$(CC) -c Ball.cc

Game.o: Game.cc Game.h
	$(CC) -c Game.cc

main.o: main.cc
	$(CC) -c main.cc

Player.o: Player.cc Player.h
	$(CC) -c Player.cc