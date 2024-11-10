# Makefile for OpenMP Hello World
#
# Jim Teresco, CSIS-335, Siena College, Fall 2024
#
CFILES=openmp_hello.c
OFILES=$(CFILES:.c=.o)
CC=clang
CFLAGS=-fopenmp=libomp

openmp_hello:	$(OFILES)
	$(CC) $(CFLAGS) -o openmp_hello $(OFILES)

clean::
	/bin/rm -f openmp_hello $(OFILES)
