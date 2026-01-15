#include<iostream>
#include<concepts>

std::integral auto add(std::integral auto a, std::integral auto b){
   return a + b;
}

int main(){

   std::floating_point auto x = add(7, 8);

   return 0;
}