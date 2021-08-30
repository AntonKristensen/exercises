#include <math.h>
#include <stdio.h>
#include <gsl/gsl_sf_erf.h>


int main(void){

	for(int i=0; i<5; i++){
		double value = erf(i);
		printf("erf(%i) er %f \n",i,value);
	}

	for(int i=0; i<5; i++){
		double value = gsl_sf_erf(i);
		printf("gsl_sf_erf(%i) er %f \n",i,value);
	}



	return 0;
}
