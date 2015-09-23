#ifndef __SCHED_NOMIS__
#define __SCHED_NOMIS__

#include <vector>
#include <queue>
#include <map>
#include "basesched.h"


class SchedNoMistery : public SchedBase {
  public:
    SchedNoMistery(std::vector<int> argn);
    ~SchedNoMistery();
    virtual void load(int pid);
    virtual void unblock(int pid);
    virtual int tick(int cpu, const enum Motivo m);  

  private:
    int next(int cpu);
    int quantumActual;
    std::vector<int> quantum; // el valor de cada quantum
    std::vector<std::queue<int> > colasXQuantum; // la cola de tareas cada quantum
    std::map<int,int> pid_quantum;
    bool colasVacias();

};

#endif
