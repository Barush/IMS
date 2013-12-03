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

all: tunel sklad posta

tunel: tunel.cpp
	$(CC) $(CFLAGS) -o $@ tunel.cpp $(PFLAGS)

sklad: sklad.cpp
	$(CC) $(CFLAGS) -o $@ sklad.cpp $(PFLAGS)

posta: posta.cpp
	$(CC) $(CFLAGS) -o $@ posta.cpp $(PFLAGS)

rebuild: clean all

clean:
	rm -f tunel  sklad *.out
