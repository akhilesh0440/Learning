 #include<iostream>
 
 int main(){

   /*
   // caputure lists
   double a{10};
   double b{20};

   auto func = [a, b](){
      std::cout << "a + b :" << a + b << std::endl;
   };
   func();

   */
   
   /*
   // Capture by value
   int c{42};
   auto func = [c](){
      std::cout << "Inner value" << c << std::endl;
   };

   for(size_t i=0; i<5; i++){
      std::cout << "outer value " << c << std::endl;
      std::cout << std::endl;
      func();
      ++c;
   }

   */
// Capture by ref
   int c{42};
   auto func = [&c](){
      std::cout << "Inner value" << c << std::endl;
   };

   for(size_t i=0; i<5; i++){
      std::cout << "outer value " << c << std::endl;
      std::cout << std::endl;
      func();
      ++c;
   }
   
   return 0;

 }