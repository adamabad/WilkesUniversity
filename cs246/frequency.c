// File: frequency.c
// Date: April 17, 2018
// Author: Adam Abad

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <ctype.h>

#define SIZE_OF_ARRAY 100000

struct item {
  char *word;
  int count;
};

enum state {
  IN_WORD, NOT_IN_WORD
};

enum list {
  IN_LIST, NOT_IN_LIST
};

void shift(struct item *wholeList, char *word) {
  int i = 0;
  for(;i < SIZE_OF_ARRAY; i++) {
    if(strlen(wholeList[i].word) == 0)
      break;
    if (strcmp(word,wholeList[i].word) < 0) {
      for(int x = SIZE_OF_ARRAY - 1;x >= i; x--) {
	if(strlen(wholeList[x].word) > 0) {
	  wholeList[x + 1].word = malloc(256 *sizeof(char));
	  wholeList[x + 1].word = strdup(wholeList[x].word);
	  free(wholeList[x].word);
    	  wholeList[x + 1].count = wholeList[x].count;
    	}
      }
      break;
    }
  }
  wholeList[i].word = strdup(word);
  wholeList[i].count = 1;
}

void search(struct item *wholeList, char *newWord) {

  enum state list = NOT_IN_LIST;
  
  for(int i = 0; i < SIZE_OF_ARRAY; i++) {
    //printf("%s %s\n", wholeList[i].word, newWord);
    if(strlen(wholeList[i].word) > 0) {
      if(strcmp(wholeList[i].word, newWord) == 0) {
	list = IN_LIST;
	wholeList[i].count++;
	break;
      }
    }
    else {
      break;
    }
  }
  
  if(list == NOT_IN_LIST) {
    shift(wholeList,newWord);
  }
}

void read(FILE *in, struct item *wholeList) {

  int c;
  enum state state = NOT_IN_WORD;
  char *word = NULL;

  while ((c = getc(in)) != EOF) {
    switch (state) {
    case IN_WORD:
      if(isspace(c)) {
	state = NOT_IN_WORD;
	search(wholeList,word);
	free(word);
      }
      else {
	c = tolower(c);
	if (isalpha(c)) {
	strcat(word,(char *)&c);
	}
      }
      break;
    case NOT_IN_WORD:
      if(!isspace(c)) {
	word = malloc(sizeof(256));
        c = tolower(c);
	if (isalpha(c)) {
	    strcat(word,(char *)&c);
	}
	state = IN_WORD;
      }	  
      break;
    }
  }
}

// https://www.geeksforgeeks.org/comparator-function-of-qsort-in-c/
// Used for typesetting the word1Value/word2Value without having to cast as 'struct item' in seperate lines
int compare(const void *word1, const void *word2) {
  int word1Value = ((struct item *) word1)->count;
  int word2Value = ((struct item *) word2)->count;
  return (word2Value - word1Value);
}

void printList(struct item *wholeList) {

  qsort(wholeList, SIZE_OF_ARRAY, sizeof(struct item), compare);
  int i = 0;
  printf("Frequency  Word\n");
  while(wholeList[i].count > 0) {
    printf("%5d       %s\n", wholeList[i].count, wholeList[i].word);
    i++;
  }
}

int main(int argc, char *argv[]) {

  struct item *wholeList = calloc(SIZE_OF_ARRAY, sizeof(struct item));

  for(int i; i < SIZE_OF_ARRAY;i++) {
    wholeList[i].word = malloc(256 * sizeof(char));
    wholeList[i].count = 0;
  }
  
  if (argc == 1) {
    read(stdin,wholeList);
  }
  else {
    for (int i = 1; i < argc; i++) {
      FILE *fin = fopen(argv[i], "r");
      if (fin == NULL) {
	fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], strerror(errno));
      }
      else {
	read(fin,wholeList);
	fclose(fin);
      }
    }
  }
  printList(wholeList);
  free(wholeList);
}

