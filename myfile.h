
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define mtype int

//some func about file operations

//to wirte the array(int) to the file
int writeToFile(int * arr, int n, char * fileName);

//to read from the file
int * readFromFile(char * fileName, int size);

