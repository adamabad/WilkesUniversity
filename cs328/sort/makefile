CFLAGS = -c -Wall -g
LFLAGS = -g -o sort

sort: sort.o 
	g++ sort.o $(LFLAGS)

sort.o: sort.cpp 
	g++ $(CFLAGS) sort.cpp

clean:
	rm -f sort *.o *~ *#
