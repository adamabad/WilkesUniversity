// File: filetree.c
// Date: April 10, 2018
// Author: Adam Abad

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void directSearch(char *dPath, int depth) {

    DIR *directory = opendir(dPath);
    struct dirent *dirRead;

    while((dirRead = readdir(directory)) != NULL) { 
      if(strcmp(dirRead->d_name,".") && strcmp(dirRead->d_name,"..")) {
	for(int x = 0; x < depth; x++) {
	  printf("    ");
	}
	printf("|- %s\n",dirRead->d_name);
	
	//Directory Check
	struct stat directCheck;
	char *subPath = malloc(sizeof(dPath)
				 + sizeof("/")
				 + sizeof(dirRead->d_name)
				 + sizeof("\0"));
	strcpy(subPath,dPath);
	strcat(subPath,"/");
	strcat(subPath,dirRead->d_name);
	strcat(subPath,"\0");
	
	stat(subPath, &directCheck);
	if(S_ISDIR(directCheck.st_mode)){
	  //printf("%s",subPath);
	  directSearch(subPath,depth + 1);
	  free(subPath);
	}
      }
    }
    closedir(directory);
}

int main(int argc, char *argv[]) {
  if(argv[1]) {

    DIR *direc = opendir(argv[1]);

    if(direc == NULL) {
      fprintf(stderr, "%s: %s: %s\n", argv[0], argv[1], strerror(errno));
      exit(1);
    }
    
    printf("\n%s\n",argv[1]);
    directSearch(argv[1],0);
    printf("\n");
  }
  
  else {
    fprintf(stderr, "usage: %s must have a command line arguement\n",argv[0]);
    exit(1);
  }
}
