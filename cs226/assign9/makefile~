CFLAGS = -c -Wall -g
LFLAGS = -g -o assign7

assign7: assign7.o sbinarytree.o BTstack.o
	g++ assign7.o sbinarytree.o BTstack.o $(LFLAGS)

assign7.o: assign7.cpp sbinarytree.h BTstack.h
	g++ $(CFLAGS) assign7.cpp

sbinarytree.o: sbinarytree.cpp sbinarytree.h BTstack.h
	g++ $(CFLAGS) sbinarytree.cpp

BTstack.o: BTstack.cpp BTstack.h
	g++ $(CFLAGS) BTstack.cpp

clean:
	rm -f assign7 *.o *~ *#
