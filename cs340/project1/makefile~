CFLAGS = -c -Wall -g
LFLAGS = -g -o pipecalc

assign61: pipecalc.o
	g++ pipecalc.o $(LFLAGS)

assign61.o: pipecalc.cpp
	g++ $(CFLAGS) pipescalc.cpp

clean:
	rm -f pipecalc *.o *~ *#
