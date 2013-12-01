#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "simlib.h"

using namespace std;

Histogram generator_h("GENERATOR", 0, 1, 35);

double lastTime = 0;

class Generator : public Event{
	void Behavior(){
		cout << Time <<": Generated" << endl;
		generator_h(Time - lastTime);
		lastTime = Time;
		//double next = Beta(2, 150, 0, 290);
		double next = Poisson(1);
		next += Random();
		if(next < 0)
			next = -next;
		Activate(Time + next*5);
	}
};

int main(){

	SetOutput("generator.out");

	Init(0, 120*60);
	(new Generator)->Activate();
	Run();

	generator_h.Output();

	return EXIT_SUCCESS;
}
