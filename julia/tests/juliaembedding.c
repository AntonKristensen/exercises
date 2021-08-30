#include <julia.h>
#include "stdio.h"


JULIA_DEFINE_FAST_TLS() //makes stuff go weeeee


int main(void){


jl_init();  //should start julia coding in here

jl_eval_string("  print(2.14)   "); //I think I run the code in here

jl_atexit_hook(0); //makes sure julia closes nicely with no open files and not mid writing or saving etc or something like that


return 0;
}
