#include "stdio.h"
#include "komplex.h"
#include "math.h"

void komplex_print (char *s, komplex a) {
	printf("%s (%g,%g)\n",s,a.re,a.im);
}

komplex komplex_new (double x, double y) {
	komplex z = {x,y};
}

void komplex_set (komplex* z,double x, double y){
	(*z).re = x;
	(*z).im = y;
}

komplex komplex_add (komplex a, komplex b) {
	komplex result = {a.re + b.re, a.im + b.im};
	return result;
}

/*
int komplex_equal ()
*/

komplex komplex_mul (komplex a, komplex b) {
	komplex result = {a.re * b.re - a.im * b.im, a.re*b.im + a.im*b.re};
	return result;
}

komplex komplex_div (komplex a, komplex b){
	komplex result = {(a.re*b.re + a.im*b.im)/(b.re*b.re + b.im*b.im),(a.im*b.re - a.re*b.im)/(b.re*b.re + b.im*b.im)};
	return result;
}

komplex komplex_conjugate (komplex z){
	komplex result = {z.re , -z.im};
	return result;
}

double komplex_abs (komplex z){
	double result = pow(z.re,2) + pow(z.im,2);
	return result;
}

komplex komplex_exp (komplex z){
	komplex result = {exp(z.re)*cos(z.im) , exp(z.re)*sin(z.im)};
	return result;
}

komplex komplex_sin (komplex z){
	komplex result = {sin(z.re)*cosh(z.im) , cos(z.re)*sinh(z.im)};
	return result;
}

komplex komplex_cos (komplex z){
	komplex result = {cos(z.re)*cosh(z.im) , - sin(z.re)*sinh(z.im)};
	return result;
}

/*
komplex komplex_sqrt (komplex z){
	komplex result = {};
	return result;
}
*/
