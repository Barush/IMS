#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "simlib.h"

using namespace std;

Histogram generator_h("POSTA", 0, 30, 21);

class Generator : public Event{
	//pri kazdem zavolani generuje minutu pracovniho dne, ve ktere prijde dalsi zakaznik
	void Behavior(){
		double next;
		double rnd = Random();

		if(rnd < 0.2358){
			do{
				next = Gama(1.8, 30);
			}while(next > 150);
			generator_h(150 - next);			
		}
		else if(rnd < 0.4607){
			do{
				next = Beta(3, 1, -200, 285);
			}while((next < 150) || (next > 285));
			generator_h(next);	
		}
		else if(rnd < 0.766){
			do{
				next = Beta(1, 3, 285, 800);
			}while((next > 480) || (next < 285));
			generator_h(next);	
		}
		else {
			do{
				next = Gama(2.5, 40);
			}while((next > 180) || (next < 30));		//630 - 450 (maximalni hodnota - posunuti fce)
			generator_h(next + 450);	
		}
		Activate(Time + 1);
	}
};

int main(){

	SetOutput("posta.out");
	RandomSeed(time(NULL));

	Init(0, 1106);
	(new Generator)->Activate();
	Run();

	generator_h.Output();

	return EXIT_SUCCESS;
}
