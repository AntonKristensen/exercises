#include "komplex.h"
#include "stdio.h"


int main(void){
	komplex a = {1,2};
	komplex b = {3,4};

	komplex jens = komplex_exp(b);

	komplex_print("a er ",a);
	komplex_print("exp(b) er ",jens);

	return 0;
}
