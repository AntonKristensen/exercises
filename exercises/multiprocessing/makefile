#makefile til at lave matematik
CC = gcc
Cflags = -O -std=gnu11 -pthread
LDLIBS = -lm
MAINFILE = montecarlo #name of the main file where i do like int main(void), and call the file like "main.c"


default: out.txt
	cat out.txt

out.txt: $(MAINFILE)
	./$(MAINFILE) 10 1 > out.txt

compiling: $(MAINFILE).o
	$(CC) -o (MAINFILE) $(MAINFILE).o

linking: $(MAINFILE).c
	$(CC) $(CFLAGS) -c $(MAINFILE).c

.PHONY: clean
clean:
	$(RM) $(MAINFILE).o $(MAINFILE) out.txt

.PHONY: test
test:
	echo $(LDLIBS)
	echo $(CC)
	echo $(RM)

