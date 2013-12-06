/******************************************************************************/
/************************* PROJEKT DO PREDMETU IMS ****************************/
/***************************** Zadani cislo 5 *********************************/
/******************************************************************************/
/************** Barbora Skrivankova, xskriv01@stud.fit.vutbr.cz****************/
/******************* Jan Krocil, xkroci02@stud.fit.vutbr.cz********************/
/******************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "simlib.h"

using namespace std;

Histogram generator_h("SKLAD", 0, 1, 24);

double lastTime = 0;	//zacatek simulace

//prepsat na generator nahodneho rozlozeni, ne na generovani procesu...

class Generator : public Event{
	//pri kazdem zavolani generuje hodinu dne, ve ktere prijede dalsi auto
	void Behavior(){
		lastTime = Time;				//aktualni cas je nula pro dalsi generovani
		double next;
		double rnd = Random();
		if(rnd < 0.284){
			//normalni rozlozeni 5-8
			next = Normal(3.7, 1.4);
			generator_h(next + 4);
		}
		else if(rnd < 0.635){
			//uniformni rozlozeni 9-11
			next = Uniform(9,11);
			generator_h(next);
		}
		else{
			//normalni rozlozeni 11-15
			next = Normal(3.4, 1.6);
			generator_h(next + 10);
		}
		Activate(Time + 1);
	}
};

int main(){

	SetOutput("sklad.out");
	RandomSeed(time(NULL));

	Init(0, 80);
	(new Generator)->Activate();
	Run();

	generator_h.Output();

	return EXIT_SUCCESS;
}
