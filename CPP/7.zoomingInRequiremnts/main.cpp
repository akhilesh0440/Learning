#include<iostream>
#include<concepts>


template <typename T>
concept TinyType = requires(T t){
   sizeof(T) < 4; // Simple requirement: Only enforces syntax
   requires sizeof(T) <= 4;
};

TinyType auto add(TinyType auto a, TinyType auto b){
   return a + b;
}


int main(){

   char x{67};
   char y{79};

   auto result = add(x, y);;
   std::cout << "Result : " << result << std::endl;

   return 0;
}