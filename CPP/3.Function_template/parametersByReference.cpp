 #include<iostream>
 #include<string>

template <typename T>  T maximum( T a,  T b);

int main(){
   int a{10};
   int b{23};
   double c{34.7};
   double d{23.4};
   std::string e{"hello"};
   std::string f{"world"};

   // Explicit temple arguments
   std::cout << "Out - &a: " << &a << std::endl;
   auto max = maximum(a, b);
   std::cout << "max : " << max << std::endl;

   return 0;
}

template <typename T>  T maximum( T a,  T b){
   ++a;
   std::cout << "In - &a: " << &a << std::endl;
   return (a > b) ? a : b;
}

