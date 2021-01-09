CFLAGS = -c -Wall -g
LFLAGS = -g -o mapcolor

mapcolor: mapcolor.o
	g++ mapcolor.o $(LFLAGS)

mapcolor.o: mapcolor.cpp
	g++ $(CFLAGS) mapcolor.cpp

clean:
	rm -f mapcolor *.o *~ *#
