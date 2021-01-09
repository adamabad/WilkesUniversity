CFLAGS = -c -Wall -g
LFLAGS = -g -o huffmancode

huffmancode: huffmancode.o PQHeap.o huffman.o
	g++ huffmancode.o PQHeap.o huffman.o $(LFLAGS)

huffmancode.o: huffmancode.cpp PQHeap.h huffman.h
	g++ $(CFLAGS) huffmancode.cpp

huffman.o: huffman.cpp huffman.h
	g++ $(CFLAGS) huffman.cpp

PQHeap.o: PQHeap.cpp PQHeap.h
	g++ $(CFLAGS) PQHeap.cpp

clean:
	rm -f huffmancode *.o *~ *#
