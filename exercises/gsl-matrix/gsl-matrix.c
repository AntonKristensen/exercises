#include <stdio.h>
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_linalg.h>

int main(){

/*definer min matrix og sæt værdier. Husk index fra nul [OpkastEmoji]. */
gsl_matrix * M = gsl_matrix_alloc(3,3);


gsl_matrix_set(M,0,0,6.16);
gsl_matrix_set(M,0,1,-2.90);
gsl_matrix_set(M,0,2,5.86);
gsl_matrix_set(M,1,0,8.08);
gsl_matrix_set(M,1,1,-6.31);
gsl_matrix_set(M,1,2,-3.89);
gsl_matrix_set(M,2,0,-4.36);
gsl_matrix_set(M,2,1,1.00);
gsl_matrix_set(M,2,2,0.19);


/* making a copy since the blas function will ruin our original one :( */
gsl_matrix * M_copy = gsl_matrix_alloc(3,3);
gsl_matrix_memcpy(M_copy,M);



/* Skriv matrix ud i en tekstfil jeg har kaldt stuff.txt*/

/*
FILE* stream = fopen("stuff.txt","w");

gsl_matrix_fprintf(stream,M,"%f");

fclose(stream);
*/


/* Skriv matrix ud i stdout, som jo så bliver smidt i out.txt med den makefile jeg har */
gsl_matrix_fprintf(stdout,M_copy,"%f");



/* definér vektorer, sæt værdier til b som har løsningen i det der ligningssystem */
gsl_vector * x = gsl_vector_alloc(3);

gsl_vector * b = gsl_vector_alloc(3);

gsl_vector_set(b,0,6.23);
gsl_vector_set(b,1,5.37);
gsl_vector_set(b,2,2.29);


/* solving the system of equations or something */
gsl_linalg_HH_solve(M,b,x);


fprintf(stdout,"is the matrix, then we multiply it by:\n");

gsl_vector_fprintf(stdout,x,"%f");

fprintf(stdout, "and then we get:\n");


/* ok trying to use blas to find A * b. This is way too complicated. I wanna go back to julia :( */
gsl_vector * result = gsl_vector_alloc(3);
gsl_blas_dgemv(CblasNoTrans, 1, M_copy, x, 0, result); /* remember that the original M got ruined >:[ */

gsl_vector_fprintf(stdout,result,"%f");













/* freeing up memory so my computer doesn't get depression */
gsl_vector_free(x);
gsl_vector_free(b);
gsl_vector_free(result);
gsl_matrix_free(M);
gsl_matrix_free(M_copy);


return 0;
}
