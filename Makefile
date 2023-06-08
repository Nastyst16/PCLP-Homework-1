# Copyright 2022 Echipa PCLP1

# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99

# define targets
TARGETS = infinite_product simple_queries gigel_and_the_checkboard another_queries

build: $(TARGETS)

infinite_product: infinite_product.c
	$(CC) $(CFLAGS) infinite_product.c -lm -o infinite_product function_1.c

simple_queries: simple_queries.c
	$(CC) $(CFLAGS) simple_queries.c -o simple_queries function_2.c

gigel_and_the_checkboard: gigel_and_the_checkboard.c
	$(CC) $(CFLAGS) gigel_and_the_checkboard.c -o gigel_and_the_checkboard function_3.c

another_queries: another_queries.c
	$(CC) $(CFLAGS) another_queries.c -o another_queries function_4.c

pack:
	zip -FSr 3XYCA_FirstnameLastname_Tema1.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
