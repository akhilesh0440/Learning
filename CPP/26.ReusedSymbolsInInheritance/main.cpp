#include <iostream>
#include "child.h"
int main(){

   Child child;
   child.print_var();
   child.Parent::print_var();

   child.show_values();
    return 0;
};