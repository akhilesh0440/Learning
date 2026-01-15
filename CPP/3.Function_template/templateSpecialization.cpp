 #include<iostream>
 #include<cstring>

//  To change the datatype of the template.

template <typename T>  T maximum( T a,  T b);

template <>
const char* maximum<const char*>(const char* a, const char* b);

int main(){
   /*
   int a{10};
   int b{23};
   double c{34.7};
   double d{23.4};
   std::string e{"hello"};
   std::string f{"world"};

   // Explicit temple arguments
   auto max_int = maximum(a, b);
   auto max_double = maximum(c, d);
   auto max_string = maximum(e, f);
   std::cout << "max int : " << max_int << std::endl;
   std::cout << "max double: " << max_double << std::endl;
   std::cout << "max string: " << max_string << std::endl;

   */

   const char* g{"wild"};
   const char* h{"animal"};

   const char* max = maximum(g, h);
   return 0;
}

template<>
const char* maximum<const char*>(const char* a, const char* b){
   return (std::strcmp(a, b) > 0) ? a : b;
};

template <typename T>  T maximum( T a,  T b){
   return (a > b) ? a : b;
}

