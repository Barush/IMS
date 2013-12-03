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
		if(Time > 0){
			//inicializace generatoru neni vystupem
			generator_h(Time - lastTime);	//cas od posledniho generovani == v kolik hodin (od 0) auto prijelo
		}

		lastTime = Time;				//aktualni cas je nula pro dalsi generovani
		double next;
		/*
		Varianta s moznosti pouzit jen jedno rozlozeni
		do{
			next = Normal(6, 2);
		}while(next < 0); //normalni rozlozeni muze generovat zaporna cisla
		Activate(Time + next + 4);			//naplanovani prijezdu dalsiho nakladaku
		*/
		double rnd = Random();
		if(rnd < 0.284){
			//normalni rozlozeni 5-8
			next = Normal(3.7, 1.4);
			Activate(Time + next + 4);
		}
		else if(rnd < 0.635){
			//uniformni rozlozeni 9-11
			next = Uniform(9,11);
			Activate(Time + next);
		}
		else{
			//normalni rozlozeni 11-15
			next = Normal(3.4, 1.6);
			Activate(Time + next + 10);
		}




	}
};

int main(){

	SetOutput("sklad.out");
	RandomSeed(time(NULL));

	Init(0, 900);
	(new Generator)->Activate();
	Run();

	generator_h.Output();

	return EXIT_SUCCESS;
}
