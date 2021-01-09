
CFLAGS = -c -Wall -g
LFLAGS = -g -o assign10

assign10: assign10.o graph.o queuei.o
	g++ assign10.o graph.o queuei.o $(LFLAGS)

assign10.o: assign10.cpp graph.h queuei.h
	g++ $(CFLAGS) assign10.cpp

graph.o: graph.cpp graph.h queuei.h
	g++ $(CFLAGS) graph.cpp

queuei.o: queuei.cpp queuei.h
	g++ $(CFLAGS) queuei.cpp

clean:
	rm -f assign10 *.o *~ *#
