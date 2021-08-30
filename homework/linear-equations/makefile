#makefile til at lave matematik
CC = gcc
Cflags = -O -std=gnu11
LDLIBS = -lm -lgsl
MAINFILE = linear #name of the main file where i do like int main(void), and call the file like "main.c"
# The name of this variable should not be "main.c" but just "main"

default: out.txt
	cat out.txt

out.txt: $(MAINFILE)
	./$(MAINFILE) > out.txt


#linking
$(MAINFILE): $(addsuffix .o,$(MAINFILE))
	$(CC) $^ $(LDLIBS) -o $@

#compiling
$(addsuffix .o,$(MAINFILE)): $(addsuffix .c,$(MAINFILE))
	$(CC) $(CFLAGS) -c $^


# I think this should work to give me a plotting macro maybe?
plots: gnuplotting
	gnuplot -e 'load "gnuplotting"'

# I think this should work to give me a pdf from latex maybe? Yep! Call the latex file for "mainfile.tex"
report: $(addsuffix .tex,$(MAINFILE))
	pdflatex $^




.PHONY: clean
clean:
	$(RM) $(MAINFILE)
	$(RM) $(addsuffix .o,$(MAINFILE))
	$(RM) out.txt
	$(RM) $(addsuffix .dvi,$(MAINFILE))
	$(RM) $(addsuffix .pdf,$(MAINFILE))
	$(RM) $(addsuffix .log,$(MAINFILE))
	$(RM) $(addsuffix .aux,$(MAINFILE))
	$(RM) $(addsuffix .out,$(MAINFILE))
	$(RM) $(addsuffix Notes.bib,$(MAINFILE))

.PHONY: test
test:
	echo $(LDLIBS)
	echo $(CC)
	echo $(RM)
