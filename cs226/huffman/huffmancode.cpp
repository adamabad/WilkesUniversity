//******************************************************************
// File: huffmancode.cpp
// Author: Adam Abad
// Date: 4/22/19
// Program Name: Huffman Code
//
// This implementation of the huffman code uses a priority queue
// as a heap to store the initial reading from the scanned file.
// after the file is parsed, the code generates the huffman code for
// the file.
// 
// The program has been tested and works properly. However, test 1
// had a variance in code produced compared to the supplied example.
//******************************************************************

//******************************************************************
// Driver Program for HuffmanCode
// Main driver program for testing huffman.cpp
// Uses a priority queue heap and a binary tree to simulate a huffman code.
//******************************************************************

#include "huffman.h" 
using namespace std; 
void header() {
  cout<<"\nName: Adam Abad\n";
  cout<<"Huffman Code\n";
  cout<<"Uses a priority heap and binary tree to construct a Huffman Code.\n\n";
}
int main() { 
  header();
  string fn; 
  cout<<"enter the name of a file containing the characters";
  cin>>fn; 
  cout<<endl;
  huffman myhuffman(fn); 
  myhuffman.displayCode(); 
}//end main
