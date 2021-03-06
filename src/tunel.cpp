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

Histogram generator_h("TUNEL", 0, 1, 35);

double lastTime = 0;

class Generator : public Event{
	void Behavior(){
		if(Time > 0){
			//inicializace generatoru neni vystupem
			generator_h(Time - lastTime);
		}
		lastTime = Time;
		double next;

		if(Random() < 0.046){		//4.6% aut projelo zaraz (interval 0-1)
			next = Uniform(0, 1);
			Activate(Time + next);
		}
		else{
			next = Gama(1, 4);
			Activate(Time + next + 1);
		}
	}
};

int main(){

	SetOutput("tunel.out");
	RandomSeed(time(NULL));

	Init(0, 120*60);
	(new Generator)->Activate();
	Run();

	generator_h.Output();

	return EXIT_SUCCESS;
}
