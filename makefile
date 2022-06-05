CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: demineur

%.o : %.c MessageBienvenue.h Interface.h
	$(CC) -c $< -o $@

demineur: $(OBJ)
	$(CC) $^  -o $@
