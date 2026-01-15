 #include<iostream>
 #include<string>

template <typename T> 
T maximum(T a, T b){
   return (a>b)? a:b;
}

// template <typename T>
// T multipy(T a, T b){
//    return a*b;
// }

int main(){

   double x{5};
   double y{7};
   auto result = maximum(x, y);
   std::cout << "result : " << result << std::endl;
   return 0;
}