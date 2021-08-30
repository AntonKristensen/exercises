#include <stdio.h>
#include <math.h>


void main(){

FILE* gnuplot;
gnuplot = popen("gnuplot -persist","w");
if(gnuplot != NULL)
fprintf(gnuplot,"plot x**2 smooth frew w boxes \n");

}
