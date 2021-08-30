#include <stdio.h>
#include <math.h>
#include <gsl/gsl_interp.h>
#include <gsl/gsl_spline.h>
#include <gsl/gsl_errno.h>
#include <stdlib.h>

/* define the functions */
/* In hindsight, because of the amount of functions, it might have been better to define the interpolation
functions in a seperate file and then include it. It would certainly be prettier. That's the disadvantage
of slowly building up your program, I guess. And I just can't be bothered to change it now :] */
double linterp(int n, double* x, double* y, double z);
double intlinterp(int n, double* x, double* y, double z);

typedef struct {int n; double *x; double *y; double *b; double *c;} qinterp;
qinterp* qinterp_alloc(int n, double* x, double* y);
void qinterp_free(qinterp *s);
double qinterp_eval(qinterp *s, double z);
double diffqinterp_eval(qinterp *s, double z);
double intqinterp_eval(qinterp *s, double z);





int main(){

int length = 20;
/* I could have made it so that the main function takes length etc as input, but I thought that the
point of the homework was more about make the interpolations, and so the main is just used to
show off that it works. */

/* making a x^2 in "length" number of points to interpolate. */
double x[length];
double y[length];

for(int i=0;i<length;i++){
	x[i] = (double) i;
}



for(int i=0;i<length;i++){
	y[i] = sin(x[i])*exp(-x[i]/5);
}




/* writing it out into files so I can plot them */

FILE* datastream = fopen("./data/data.data","w+");
for(int i=0;i<length;i++){
fprintf(datastream,"%f\t%f\n",x[i],y[i]);
}
fclose(datastream);





/* Now make the linear interpolation as a lot of points so we can plot it */
FILE* linterpstream = fopen("./data/linterp.data","w+");
for(double i=0;i<length*10;i++){
fprintf(linterpstream,"%f\t%f\n",i/10,linterp(length,x,y,i/10));
}
fclose(linterpstream);

/* The integrated from the linear interpolation */
FILE* intlinterpstream = fopen("./data/intlinterp.data","w+");
for(double i=0;i<length*10;i++){
fprintf(intlinterpstream,"%f\t%f\n",i/10,intlinterp(length,x,y,i/10));
}
fclose(intlinterpstream);




/* Ok now to make comparisons with the GSL implementation also */

gsl_interp_accel *gsllinterpacc = gsl_interp_accel_alloc();
gsl_spline *gsllinterp = gsl_spline_alloc(gsl_interp_linear,length);
gsl_spline_init(gsllinterp,x,y,length);

FILE* gsllinterpstream = fopen("./data/gsllinterp.data","w+");
for(double i=0; i<=length-1; i+=0.1){
fprintf(gsllinterpstream,"%f\t%f\n",i,gsl_spline_eval(gsllinterp,i,gsllinterpacc));
}
fclose(gsllinterpstream);

FILE* gslintlinterpstream = fopen("./data/gslintlinterp.data","w+");
for(double i=0; i<=length-1; i+=0.1){
fprintf(gslintlinterpstream,"%f\t%f\n",i,gsl_spline_eval_integ(gsllinterp,x[0],i,gsllinterpacc));
}
fclose(gslintlinterpstream);


/* And now making plots for the quadratic interpolation! */
qinterp* quaddo = qinterp_alloc(length,x,y);

FILE* qinterpstream = fopen("./data/qinterp.data","w+");
for(double i=0; i<=length-1; i+=0.1){
fprintf(qinterpstream,"%f\t%f\n",i,qinterp_eval(quaddo,i));
}

FILE* diffqinterpstream = fopen("./data/diffqinterp.data","w+");
for(double i=0; i<=length-1; i+=0.1){
fprintf(diffqinterpstream,"%f\t%f\n",i,diffqinterp_eval(quaddo,i));
}

FILE* intqinterpstream = fopen("./data/intqinterp.data","w+");
for(double i=0; i<=length-1; i+=0.1){
fprintf(intqinterpstream,"%f\t%f\n",i,intqinterp_eval(quaddo,i));
}




/* oops i need to free the memory of the spline objects also! */
gsl_spline_free(gsllinterp);
gsl_interp_accel_free(gsllinterpacc);

qinterp_free(quaddo);





















return 0;
}













/* write the methods of the functions */

double linterp(int n, double* x, double* y, double z){

int i=0, j=n-1;

/* this is the binary search. Stuff like this is so infinitely easier in matlab and Julia, where you can just 
find the index for which x[i] < z < x[i+1]. Though maybe it might not be faster, the implementation in Julia
is probably actually optimized pretty well, as stuff usually is in Julia */
while(j-i>1){
	int m=(i+j)/2;

	if(z>x[m]){
		i=m;
	}
	else{
		j=m;
	}
}

double dy=y[i+1]-y[i], dx=x[i+1]-x[i];

return y[i] + dy/dx * (z-x[i]);



}






/* The integral of the linear interpolation */
double intlinterp(int n, double* x, double* y, double z){

int i=0, j=n-1;

while(j-i>1){
	int m=(i+j)/2;

	if(z>x[m]){
		i=m;
	}
	else{
		j=m;
	}
}

double dy=y[i+1]-y[i], dx=x[i+1]-x[i];

/* We are interested in the value of the integral int_x(0)^x, so we must find the values for all the pieces*/
/* up until we get to the piece where z lies in.*/
double result = 0;
for(int l=0;l<i;l++){
result = result + y[l]*(x[l+1]-x[l]) + (y[l+1]-y[l])/(x[l+1]-x[l]) * pow(x[l+1]-x[l], 2) / 2;
}

/*
Now we add the last part from the last point up to z
if z = x[i] then this last line just is just result = result + 0
*/
result = result + y[i]*(z - x[i]) + dy/dx*(z-x[i])*(z-x[i])/2;

return result;
}










/* The quadratic interpolation
I would have liked if it was just a simple function where you could just call it to get a value, like with the linear
but unfortunately, because of the forwards and backwards recursion for the one coefficient, that's not good to do.
So I have to make it like the example in the table, where calling the quadratic spline creates a spline structure,
that you can then work with to evaluate it at points etc. :[
*/

/*
typedef struct {int n; double *x; double *y; double *b; double *c;} qinterp;
*/


qinterp* qinterp_alloc(int n, double* x, double* y){

qinterp *s = (qinterp*)malloc(sizeof(qinterp)); /* this function allocates memory for a quadratic interpolation, and calculates it */

/* allocating memory for the attributes of the structure, remember to make a freeing function for this memory */
s->b = (double*)malloc((n-1)*sizeof(double));
s->c = (double*)malloc((n-1)*sizeof(double));
s->x = (double*)malloc((n)*sizeof(double));
s->y = (double*)malloc((n)*sizeof(double));
s->n = n;

/* putting in our x and y values into this struct */
for(int i = 0; i<n; i++){
	s->x[i] = x[i];
	s->y[i] = y[i];
}



double p[n-1]; /* array for values of dy/dx */
double h[n-1]; /* array for values of dx */
/* filling in the values for these */
for(int i=0; i<n; i++){
	h[i] = x[i+1] - x[i];
	p[i] = (y[i+1] - y[i])/h[i];
}

/* now to make the first recursion upwards */
s->c[0] = 0;
for(int i=0; i<n-2; i++){
	s->c[i+1] = (p[i+1] - p[i] - s->c[i]*h[i])/h[i+1];
}

s->c[n-2] /= 2; /* wow yo this /= operator is sick. I only knew about += but it makes sense that you can do this with any standard operator! */
/* Now the downwards recursion */
for(int i=n-3; i>=0; i--){
	s->c[i] = (p[i+1] - p[i] - s->c[i+1]*h[i+1])/h[i];
}

/* And now we fill the values for the b coefficient (b = dy/dx - c*dx) into our spline struct so we can return it */
for(int i=0; i<n-1; i++){
	s->b[i]=p[i]-s->c[i]*h[i];
}


return s;
}




/* This function frees the memory that was allocated to the qinterp structure */
void qinterp_free(qinterp *s){
free(s->x);
free(s->y);
free(s->b);
free(s->c);
free(s);
}


/* This function takes as input an already calculated quadratic interpolation, and then returns the value of the
interpolation at the point that you give it */
double qinterp_eval(qinterp *s, double z){

int i = 0;
int j = s->n-1;

while(j-i>1){
	int m = (i+j)/2;
	if(z > s->x[m]){i=m;}
	else{j=m;}
}

double h = z - s->x[i]; /* this is the extra x axis space your point is compared to the i'th point */

return s->y[i] + h * (s->b[i] + h * s->c[i]);
}



/* This is like the one above, except it returns the derivative */
double diffqinterp_eval(qinterp *s, double z){

int i = 0;
int j = s->n-1;

while(j-i>1){
	int m = (i+j)/2;
	if(z > s->x[m]){i=m;}
	else{j=m;}
}

double h = z - s->x[i]; /* this is the extra x axis space your point is compared to the i'th point */

return s->b[i] + 2 * h * s->c[i];
}




/* The integral of the quadratic interpolation */
double intqinterp_eval(qinterp *s, double z){

int i=0;
int j=s->n-1;


while(j-i>1){
	int m = (i+j)/2;
	if(z > s->x[m]){i=m;}
	else{j=m;}
}



/* We are interested in the value of the integral int_x(0)^x, so we must find the values for all the pieces*/
/* up until we get to the piece where z lies in.*/
double result = 0;
for(int l=0;l<i;l++){
	double dx = s->x[l+1] - s->x[l];
	double dy = s->y[l+1] - s->y[l];

	result = result + s->y[l]*dx + s->b[l]*dx*dx/2 + s->c[l]*dx*dx*dx/3;
}

/*
Now we add the last part from the last point up to z
if z = x[i] then this last line just is just result = result + 0
*/

double dx=z - s->x[i];


result = result + s->y[i]*dx + s->b[i]*dx*dx/2 + s->c[i]*dx*dx*dx/3;

return result;
}















