#makefile til at lave en hello world
CC = gcc
Cflags = -O -std=gnu11
LDLIBS = -lm
NAME = $$USER

default: out.txt
	cat out.txt

out.txt: hello
	./hello > out.txt

hello: hello.o
	$(CC) -o hello hello.o

hello.o: hello.c
	$(CC) $(CFLAGS) -c hello.c

.PHONEY: clean
clean:
	$(RM) hello.o hello out.txt

.PHONEY: test
test:
	echo $(LDLIBS)
	echo $(CC)
	echo $(RM)
#	echo $$(NAME)

.Phoney: nameout
nameout:
	name = $$USER; echo $$name
