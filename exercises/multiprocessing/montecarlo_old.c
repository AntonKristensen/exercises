#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
/* argv[1] er antal punkter per thread, argv[2] er antal threads  */


unsigned int xseed = time(NULL);
unsigned int yseed = rand_r(&xseed);

int thread_length = atoi(argv[1]);
int thread_count = atoi(argv[2]);





int number_in[thread_count];
int *number_in_pointer = number_in;



for(int n=0; n<thread_count; n++){


	int threadnumber = n;
	int thread_in = 0;
	for(int i=0; i<thread_length;i++){
		if (pow( (double)rand_r(&xseed) / ( (double)RAND_MAX ) ,2) + pow( (double)rand_r(&yseed) / ((double)RAND_MAX) ,2) <= 1){
			thread_in++;
			/*printf("*number_in_pointer is %i\n",*number_in_pointer);*/
		}
	}
	*(number_in_pointer+threadnumber) = thread_in;




	printf("%i was in circle number %i: pi = %g \n",number_in[n],n,(double)number_in[n]*4 / (double)thread_length);

}


int sum = 0;

for(int flemming=0; flemming<thread_count; flemming++){
	sum += number_in[flemming];
}

printf("Antallet af punkter inde i cirklen er %i.\nPi = %g\n",sum,4*(double)sum / ((double)thread_length * (double)thread_count));



/*
for(int i=0; i<thread_length;i++){
	xvalues[i] =(double)rand_r(&xseed)/((double)RAND_MAX);
	yvalues[i] = (double)rand_r(&yseed)/((double)RAND_MAX);
	printf("%g %g\n",xvalues[i],yvalues[i]);
}
*/ 
/*Det her er hvis jeg vil printe arrays med random punkter i, men det fylder jo hukommelse uden grund*/




/* hovsa stacken har jo kun 8MB, så altså den kan have en million doubles i sig.
Hvis det viser sig at jeg skal bruge mere, så lav det om til malloc */

/*
for


rand_r(&seed)
*/





return 0;
}
