# Makefile for OpenMP Hello World
#
# Jim Teresco, CSIS-335, Siena College, Fall 2021
#
CFILES=openmp_hello.c
OFILES=$(CFILES:.c=.o)
# For gcc (noreaster)
CC=gcc -fopenmp

openmp_hello:	$(OFILES)
	$(CC) -o openmp_hello $(OFILES)

clean::
	/bin/rm -f openmp_hello $(OFILES)
