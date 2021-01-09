CFLAGS = -c -Wall -g
LFLAGS = -g -o assign9

assign9: assign9.o general.o
	g++ assign9.o general.o $(LFLAGS)

assign9.o: assign9.cpp general.h
	g++ $(CFLAGS) assign9.cpp

general.o: general.cpp general.h
	g++ $(CFLAGS) general.cpp
clean:
	rm -f assign9 *.o *~ *#
