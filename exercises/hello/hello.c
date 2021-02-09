#include "stdio.h" // Står vist for "standard input output"
#include "stdlib.h" // Dunno, men jeg skulle bruge det til "malloc()"
#include "math.h" // Jeg ved ikke lige helt hvad der er i den pakke endnu, og hvad der ikke er i C som standard, nok sqrt()
int main(void){
double r=sqrt(2.0);
printf("Hello, ");
//printf("hello, sqrt(2.0)=%g\n",r);
//system("echo $USER"); //gives out username. It is bad practice to use system() for security reasons or something.
char *buffer; //declares a buffer string
buffer = (char *)malloc(10*sizeof(char)); //allocates memory for it (for some reason the malloc command is not properly defined or something?)
	// It gives me nasty messages when compiling. But the program runs fine so I guess it's ok :]
cuserid(buffer); // "cuserid(some string, preferably empty I think)" gets the name of the current user, and puts it into that string.
printf("%s!\n", buffer);
return 0;
}
