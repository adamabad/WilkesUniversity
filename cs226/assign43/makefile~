CFLAGS = -c -Wall -g
LFLAGS = -g -o assign42

assign42: assign42.o listc.o
	g++ assign42.o listc.o $(LFLAGS)

assign42.o: assign42.cpp listc.h
	g++ $(CFLAGS) assign42.cpp

listc.o: listc.cpp listc.h
	g++ $(CFLAGS) listc.cpp

clean:
	rm -f assign42 *.o *~ *#
