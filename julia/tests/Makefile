CC = gcc

CFLAGS = -O -std=gnu11

LDLIBS = -lm

JULIA_CONFIG = /usr/bin/julia -e 'include(joinpath(Sys.BINDIR, Base.DATAROOTDIR, "julia", "julia-config.jl"))'






julle: julle.c
	$(CC) $^ -o $@ $(CFLAGS)


.PHONY: clean
clean:
	$(RM) julle.o julle

.PHONY: test
test:
	echo $(CC)
	echo $(JULIA_CONFIG)
