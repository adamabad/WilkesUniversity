//******************************************************************
// File: huffman.cpp
// Author: Adam Abad
// Date: 4/22/2019
// Program Name: Huffman Code
//******************************************************************

// ********************************************************
// Implementation file huffman.cpp for the the Huffman Code.
// ********************************************************

#include "huffman.h"

huffman::huffman(string fn) {
  ifstream inFile;
  inFile.open(fn.c_str());
  assert(inFile.is_open());
  cout<<"The file "<<fn<<endl;
  int charArray[26];
  char inData;
  while(true) {
    inFile>>inData;
    if(!inFile.good()) {
      inFile.clear();
      inFile.ignore(120, '\n');
    }
    if(inFile.eof()) {
      break;
    }
    charArray[inData - 'A']++;
  }
  inFile.close();
  Heap pHeap;
  for(int x = 0; x < 26; x++) {
    cout<<"char = "<<char('A' + x)<<" count = "<<charArray[x]<<endl;
    if(charArray[x] != 0) {
      huffmannode *node = new huffmannode;
      node->symbol = x + 'A';
      node->frequency = charArray[x];
      node->nodetype = 1;
      node->left = NULL;
      node->right = NULL;
      pHeap.heapInsert(*node);
    }
  }
  pHeap.heapDisplay();
  cout<<"end initial heap display\n\n";
  int num = pHeap.heapSize();
  for(int i = 1; i < num; i++) {
    huffmannode *left, *right;
    left = new huffmannode;
    right = new huffmannode;
    pHeap.heapDelete(*left);
    pHeap.heapDelete(*right);
    huffmannode *node = new huffmannode;
    node->left = left;
    node->right = right;
    node->nodetype = 0;
    node->frequency = left->frequency + right->frequency;
    cout<<" for debug p->frequency = "<<left->frequency<<" and q->frequency = "<<right->frequency<<endl;
    pHeap.heapInsert(*node);
    cout<<"just inserted frequency = "<<node->frequency<<endl;
  }
  finalhuffmantree = new huffmannode;
  pHeap.heapDelete(*finalhuffmantree);
  cout<<"the constructor has built the huffman tree\n";
}//end of function constructor

huffman::~huffman() {
  Heap pHeap;
  cout<<"Destructor executing"<<endl;
  pHeap.heapInsert(*finalhuffmantree);
  while(!pHeap.heapIsEmpty()) {
    huffmannode *node = new huffmannode;
    pHeap.heapDelete(*node);
    if(node->nodetype == 1){
      delete(node);
    }
    else {
      if(node->right != NULL) {	
	pHeap.heapInsert(*(node->right));
      }
      if(node->left != NULL) {
	pHeap.heapInsert(*(node->left));
      }
      delete(node);
    }
  }
  //work in reverse to destroy
  //put everything back in the heap one level at a time and destroy each internal node
}


void huffman::inOrder(string s,huffmannode *t) {
  if(t!=NULL) {
    inOrder(s + '0',t->left);
    if(t->nodetype == 1) {
      cout<<"Frequency = "<<t->frequency<<" the letter is "<<t->symbol;
      cout<<" the binary string is "<<s<<endl;
    }
    else {
      cout<<"Frequency = "<<t->frequency<<endl;
    }
    inOrder(s + '1',t->right);
  }
}
//list operations
void huffman::displayCode() {
  string s;
  inOrder(s,finalhuffmantree);
}
