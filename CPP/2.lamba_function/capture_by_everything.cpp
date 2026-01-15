 #include<iostream>
 
 int main(){
   /*
   // Capture everything by value
   int c{42};
   auto func = [=](){
      std::cout << "Inner value :" << c << std::endl;
   };

   for(size_t i=0; i<5; i++){
      std::cout << "Outer value :" << c << std::endl;
      func();
      ++c;
   }
      */
     int c{42};
     int d{5};
   auto func = [&](){
      std::cout << "Inner value :" << c << std::endl;
      std::cout << "Inner value d :" << d << std::endl;
   };

   for(size_t i=0; i<5; i++){
      std::cout << "Outer value :" << c << std::endl;
      func();
      ++c;
   }

   
 }