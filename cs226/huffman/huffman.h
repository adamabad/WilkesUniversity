//*********************************************************
// File: huffman.h
// Author: Adam Abad
// Date: 4/22/2019
// Program Name: Huffman Code
//*********************************************************

// ********************************************************
// Header file huffman.h for the huffman code
// ********************************************************
#include<cassert>
#include<iostream>
#include<string>
#include<fstream>
#include "PQHeap.h"
using namespace std;

class huffman {
 public:
  huffman(string fn);
  ~huffman();
  // operations
  void displayCode(); 
 private:
  void inOrder(string s,huffmannode *t) ;
  huffmannode * finalhuffmantree;
};
