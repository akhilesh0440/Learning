#include<iostream>
#include<concepts>

// Combining concepts 


template <typename T>
concept TinyType = requires(T t){
   sizeof(T) <= 4; // Simple requirement: Only enforces syntax
   requires sizeof(T) <= 4;
};

template <typename T>
requires std::floating_point<T> && TinyType<T>
T add(T a, T b) {
   return a + b;
};


int main(){

   double x{67};
   double y{79};

   // std::string e{"hello"};
   // std::string f{"World"};

   auto result = add(x, y);;
   std::cout << "Result : " << result << std::endl;

   return 0;
}