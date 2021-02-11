//Headers
#include "stdio.h"
#include "math.h"
#include "complex.h"


int main(void){


// First part of the exercise, some various functions and complex numbers
printf("Gamma(5) =  %g, \n", tgamma(5)); //tgamma(x) spytter en double ud, så jeg kan ikke bar ebruge %i, men bliver nødt til %g

printf("J_1(0.5) = %g \n",j1(0.5)); //Nu bruger vi doubles, for vi skal tage besselfunktionen af en halv

double complex root2 = csqrt(-2);
printf("sqrt(-2) = %g%+gi \n",creal(root2),cimag(root2));

double complex expi = cexp(M_PI * I);
printf("exp(i pi) = %g%+gi \n",creal(expi),cimag(expi));

double complex ei = cexp(I);
printf("exp(i) = %g%+gi \n",creal(ei),cimag(ei));

double complex ie = cpow(I,M_E);
printf("i^e = %g%+gi \n",creal(ie),cimag(ie));

double complex ii = cpow(I,I);
printf("i^i = %g%+gi \n",creal(ii),cimag(ii));



// Second part of the exercise, some precision stuff.
printf("Float 1/9 = %.25g \n",1.f/9);
printf("Double 1/9 = %.25lg \n",1./9);
printf("Long double 1/9 = %.25Lg \n",1.L/9);

printf("It should of course just be endles 0.1111.....");

return 0;
}
