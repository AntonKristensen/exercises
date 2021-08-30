#include <stdio.h>
#include <math.h>
#include <gsl/gsl_vector.h>



double expapp(double x);


int main(){

int length = 10;

double X[length];
double Y[length];


FILE* expapp_stream = fopen("expapp.data","w");

for(int i=0; i<length; i++){
	X[i] = i;
	Y[i] = expapp(i);
	fprintf(expapp_stream,"%f\t%f\n",X[i],Y[i]);
}

fclose(expapp_stream);



return 0;
}






double expapp(double x){
	double result;
	result = 1+x*(1+x/2*(1+x/3*(1+x/4*(1+x/5*(1+x/6*(1+x/7*(1+x/8*(1+x/9*(1+x/10)))))))));
	return result;
}
