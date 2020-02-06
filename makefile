FILES = nda.o
FLAGS = -Wall -Werror -g

all: build clean

build: $(FILES)
	gcc main.c $(FILES) $(FLAG)

nda.o: headers/nda.h
	gcc -c nda.c $(FLAGS)

clean:
	rm *.o
