#include "stdio.h"
#include "math.h"


int main(int argc, char** argv){
	for(int i=0; i<argc; i++){
		printf("argv[%i] is %s \n",i,argv[i]); /*Yeah I don't even bother defining the input to be whatever type, because this program only wants to use them as strings to print anyways*/
	}

	return 0;
}

/* just compile this stupid little program with "gcc -0 read-cmdline read-cmdline.c" in the terminal, cause all the file management should be in the makefile when i actually wanna do it anyways.*/

