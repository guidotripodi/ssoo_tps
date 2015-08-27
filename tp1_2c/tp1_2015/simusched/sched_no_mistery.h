#ifndef __SCHED_NOMIS__
#define __SCHED_NOMIS__

#include <vector>
#include <queue>
#include "basesched.h"

class SchedNoMistery : public SchedBase {
  public:
    SchedNoMistery(std::vector<int> argn);
    virtual void load(int pid);
    virtual void unblock(int pid);
    virtual int tick(int cpu, const enum Motivo m);  

  private:
  	std::queue<int> q;
  	std::list<int> bloqueados;
  	std::list<int> quantumsAUsar;
  	std::list<int> quantumsUsados;
	std::int quantum;
	std::int quantumActual;
};

#endif
