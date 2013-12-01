######################################
# Nazev: Makefile
# Ucel kodu: IMS projekt
#      makefile pro preklad programu generator
# Autori: Barbora Skrivankova, xskriv01, FIT VUT
#		  Jan Krocil, xkroci02, FIT VUT
# Vytvoreno: prosinec 2013
######################################
CLAGS=-g -O2 
PFLAGS=-lsimlib -lm
 
CC = g++

all: generator

generator: generator.cpp
	$(CC) $(CFLAGS) -o $@ generator.cpp $(PFLAGS)

rebuild: clean all

clean:
	rm -f generator *.out