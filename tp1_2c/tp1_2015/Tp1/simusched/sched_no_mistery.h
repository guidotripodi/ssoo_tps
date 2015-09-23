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
    int quantumActual; // el quantum restante de la tarea actual
    std::vector<int> quantum; // una lista con el valor de cada quantum
    std::vector<std::queue<int> > colasXQuantum; // una lista con la cola de tareas cada quantum
    std::map<int,int> pid_quantum; // un diccionario que me dice en que quantum de la lista esta cada tarea
    bool colasVacias(); // funcion que me indica si no hay mas tareas en ninguna cola de quantums

};

#endif
