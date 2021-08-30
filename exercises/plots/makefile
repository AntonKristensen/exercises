#makefile til at lave matematik
CC = gcc
Cflags = -O -std=gnu11
LDLIBS = -lm
MAINFILE = main #name of the main file where i do like int main(void), and call the file like "main.c"


default: out.txt
	cat out.txt

out.txt: $(MAINFILE)
	./$(MAINFILE) > out.txt

hello: $(MAINFILE).o
	$(CC) -o (MAINFILE) $(MAINFILE).o

hello.o: $(MAINFILE).c
	$(CC) $(CFLAGS) -c $(MAINFILE).c

.PHONY: clean
clean:
	$(RM) $(MAINFILE).o $(MAINFILE) out.txt

.PHONY: test
test:
	echo $(LDLIBS)
	echo $(CC)
	echo $(RM)

