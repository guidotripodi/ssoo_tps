#include <vector>
#include <queue>
#include "sched_no_mistery.h"
#include "basesched.h"
#include <iostream>
#include <stdio.h>

using namespace std;


SchedNoMistery::SchedNoMistery(vector<int> argn) {

	// Mistery recibe la cantidad de quantum por parámetro, inicializamos los quantum
	for (int i = 0; i < argn.size() ; i++){
		quantum.push_back(argn[i]);
		std::queue<int> q;
		colasXQuantum.push_back(q); 
	}

}


SchedNoMistery::~SchedNoMistery() {
}


void SchedNoMistery::load(int pid) {

	colasXQuantum[0].push(pid);
	
	pid_quantum.insert(pair<int, int> (pid,0));

}

void SchedNoMistery::unblock(int pid) {
	int nuevoQuantum = (pid_quantum.find(pid))->second;
	if(nuevoQuantum != 0 ){
		pid_quantum.erase(pid);
		nuevoQuantum--;
		pid_quantum.insert(pair<int, int> (pid,nuevoQuantum));
	}
	colasXQuantum[nuevoQuantum].push(pid);
}

int SchedNoMistery::tick(int cpu, const enum Motivo m) {
	int sig;

	switch (m) {
		case EXIT:
			return next(cpu);
			break;
		case BLOCK:
			return next(cpu);
			break;
		case TICK:
/*		llega un tick de reloj, chequeamos que esta corriendo en el cpu,
		si es la idle vemos en nuestras colas si hay alguien listo para correr
*/
			if (current_pid(cpu) == IDLE_TASK) {
				if (!colasVacias()) {
					sig = next(cpu);
					return sig;
				} else {					
					return IDLE_TASK;
				}
			} else {
		
				quantumActual--;


				if (quantumActual == 0) {
					int nuevoQuantum = (pid_quantum.find(current_pid(cpu)))->second;
					if(nuevoQuantum < (quantum.size()-1) ){
						pid_quantum.erase(current_pid(cpu));
						nuevoQuantum++;
						pid_quantum.insert(pair<int, int> (current_pid(cpu),nuevoQuantum));
					}
					colasXQuantum[nuevoQuantum].push(current_pid(cpu));
					sig = next(cpu);
					return sig;				

				} else {
					return current_pid(cpu);
				}
			}
			break;
	}
}

int SchedNoMistery::next(int cpu){
	int pid;
	for(int i = 0; i < quantum.size(); i++){
		if(!colasXQuantum[i].empty()){
			pid = colasXQuantum[i].front();
			quantumActual = quantum[i];
			colasXQuantum[i].pop();
			return pid;
		}
	}
	return IDLE_TASK;

}

bool SchedNoMistery::colasVacias(){
	for(int i = 0; i < quantum.size(); i++){
		if(!colasXQuantum[i].empty()){
			return false;
		}
	}
	return true;
}
