#makefile til at lave matematik
CC = gcc
Cflags = -O -Wall -std=gnu11
LDLIBS = -lm
MAINFILE = main #name of the main file where i do like int main(void), and call the file like "main.c"


default: out.txt
	cat out.txt

out.txt: main
	./main > out.txt

main: main.o komplex.o
	$(CC) -o main main.o komplex.o $(LDLIBS) #linking

main.o: main.c komplex.h
	$(CC) $(CFLAGS) -c main.c komplex.h #compiling main.c

komplex.o: komplex.c komplex.h
	$(CC)  $(CFLAGs) -c komplex.c komplex.h #compiling komplex.c

.PHONY: clean
clean:
	$(RM) main.o main komplex.o out.txt

.PHONY: test
test:
	echo $(LDLIBS)
	echo $(CC)
	echo $(RM)

