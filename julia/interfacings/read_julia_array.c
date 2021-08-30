#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int main(int argc, char *argv[]){
/* Første argument skal være fil den læser fra, andet argument skal være pointer til en adresse hvor den kan lægge arrayet */

FILE * stream = fopen("printed_array.data","r"); /* opens the array, should be from argv[1] */

/* Initialize variables to use in the loop*/
char c[1]; /* needs to be a pointer to a char to use strcmp() */
int rows=1,columns = 1;
while(1){
	c[0]=(char)getc(stream); /* This here advances one track down the stream and gives the char */
	if(feof(stream)){break;} /* This here stops the while loop at the end of the stream */
	if(strcmp(c," ")==0  &&  rows==1){columns+=1;} /* Counts how many columns by counting white spaces, only for first row. */
	if(strcmp(c,";")==0){rows+=1;} /* Counts how many rows by counting semicolons*/
}
fclose(stream); /* Close the stream, because getc() 'eats' the chars in the stream, so it is now useless, maybe? */



double** array = calloc(rows*columns,sizeof(double)); /* arrays med malloc er n-ranks points hvor n er dimensionen af arrayet */
/* underpointerne skal så være for hver row, for så passer det med C, at de ligger lige i rækkefølge */






stream = fopen("printed_array.data","r"); /* åbner på ny */

while(1){
	c[0]=(char)getc(stream);
	if(feof(stream)){break;}
	/*hmm*/
}


fclose(stream);


double flemming = 3.2010;

char karsten[] = "2.3545";

printf("Test arithmetic, %f + %s = %f \n",flemming,karsten,flemming+atof(karsten));



printf("%i rows, %i columns\n",rows,columns);

printf("en double er %lu bytes 	\n",sizeof(double));

array[0][0] = 3;

printf("%f  \n",array[0][0]);



free(array);
return 0;
}
