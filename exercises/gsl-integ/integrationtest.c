#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>


double f(double x, void * params){return log(x) / sqrt(x);}





int main(){

double result;
double error;
gsl_integration_workspace * workwork = gsl_integration_workspace_alloc(1000);
gsl_function F;
F.function = &f;

gsl_integration_qags(&F,0,1,0,0.001,1000,workwork,&result,&error);

printf("result = %g, error = %g \n",result,error);



gsl_integration_workspace_free(workwork);

return 0;
}
