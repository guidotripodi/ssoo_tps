#include <vector>
#include <queue>
#include "sched_no_mistery.h"
#include "basesched.h"

using namespace std;

SchedNoMistery::SchedNoMistery(vector<int> argn) {  
	for(int i = 0; i < size(argn); i++)
}

void SchedNoMistery::load(int pid) {  
	q.push(pid); // llegó una tarea nueva
}

void SchedNoMistery::unblock(int pid) {  
}

int SchedNoMistery::tick(int cpu, const enum Motivo m) {  
}
