export LC_ALL=C
CXXFLAGS= -Wall -pedantic -g -ggdb
LDFLAGS= -lpthread

OBJS=main.o simu.o basesched.o basetask.o tasks.o sched_rr.o sched_fcfs.o sched_rr2.o sched_no_mistery.o
MAIN=simusched

.PHONY: all clean new
all: $(MAIN)

$(MAIN): $(OBJS) sched_mistery.o 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)


%.o: %.cpp %.h basesched.h
basesched.o: basesched.cpp basesched.h
basetask.o: basetask.cpp basetask.h
main.o: main.cpp simu.h basetask.h basesched.h tasks.h sched_fcfs.h \
 sched_rr.h sched_rr2.h
simu.o: simu.cpp simu.h basetask.h basesched.h
simusched.o: simusched.cpp basetask.h basesched.h tasks.h
tasks.o: tasks.cpp tasks.h basetask.h

clean:
	rm -f $(OBJS) $(MAIN)

new: clean all
main_solo: main.cpp simu.h

ej= main_solo simu.o basesched.o basetask.o tasks.o sched_fcfs.o simusched

ej1: $(ej)
	./simusched mistery3 1 1 1 SchedFCFS | ./graphsched.py >> fcfs1.png

cleanej1:
	rm -f $(OBJS) $(MAIN) fcfs1.png

ej2: $(ej)
	./simusched mistery3 1 1 1 SchedFCFS | ./graphsched.py >> fcfs1.png

cleanej2:
	rm -f $(OBJS) $(MAIN) fcfs1.png

ej3: $(ej)
	./simusched mistery3 1 1 1 SchedFCFS | ./graphsched.py >> fcfs1.png

cleanej3:
	rm -f $(OBJS) $(MAIN) fcfs1.png

ej4: $(ej)
	./simusched mistery3 1 1 1 SchedFCFS | ./graphsched.py >> fcfs1.png

cleanej4:
	rm -f $(OBJS) $(MAIN) fcfs1.png

ej5: $(ej)
	./simusched mistery3 1 1 1 SchedFCFS | ./graphsched.py >> fcfs1.png

cleanej5:
	rm -f $(OBJS) $(MAIN) fcfs1.png

ej6: $(ej)
	./simusched mistery3 1 1 1 SchedFCFS | ./graphsched.py >> fcfs1.png

cleanej6:
	rm -f $(OBJS) $(MAIN) fcfs1.png

ej7: $(ej)
	./simusched mistery3 1 1 1 SchedNoMistery 5 4 2 | ./graphsched.py >> pruebamakemistery.png

cleanej7:
	rm -f $(OBJS) $(MAIN) fcfs1.png


ej8: $(ej)
	./simusched mistery3 1 1 1 SchedFCFS | ./graphsched.py >> fcfs1.png

cleanej8:
	rm -f $(OBJS) $(MAIN) fcfs1.png


cleanTodosLosEjercicios:
	rm -f $(OBJS) $(MAIN) fcfs1.png