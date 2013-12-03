#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "simlib.h"

using namespace std;

Histogram generator_h("POSTA", 0, 30, 21);

double lastTime = 0;	//zacatek simulace

class Generator : public Event{
	//pri kazdem zavolani generuje hodinu dne, ve ktere prijede dalsi auto
	void Behavior(){
		cout << Time <<": Generated" << endl;

		if(Time > 0){
			//inicializace generatoru neni vystupem
			generator_h(Time - lastTime);	//cas od posledniho generovani == v kolik hodin (od 0) auto prijelo
		}

		lastTime = Time;				//aktualni cas je nula pro dalsi generovani
		double next;
		next = Erlang(16, 50);
		Activate(Time + next);
	}
};

int main(){

	SetOutput("posta.out");
	RandomSeed(time(NULL));

	Init(0, 1000);
	(new Generator)->Activate();
	Run();

	generator_h.Output();

	return EXIT_SUCCESS;
}
