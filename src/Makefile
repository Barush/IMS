###############################################################################
# Nazev: Makefile
# Ucel kodu: IMS projekt
# Autori: Barbora Skrivankova, xskriv01@stud.fit.vutbr.cz
#		  Jan Krocil, xkroci02@stud.fit.vutbr.cz
###############################################################################
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

run:
	./tunel
	./posta
	./sklad
	cat tunel.out
	cat posta.out
	cat sklad.out

clean:
	rm -f tunel  sklad *.out
