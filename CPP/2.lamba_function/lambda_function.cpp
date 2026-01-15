 #include<iostream>


 
 int main(){

   /* 
   Lambda function signature :
                                 [caputure list](parameters) -> return type
                                          // Function body
                                 }
   */

   /*
  auto func = [](){
   std::cout << "hello world!" << std::endl;

  };

  func();

  */

//   Declare a lamba function and call it directly
 /*[](){
   std::cout << "hello world!" << std::endl;

  }();
  */

  /*
  auto func1 = [](double a, double b){
   std::cout <<"a+b : "<< (a+b) <<std::endl;
  };
  */

  //Lambda function with return value
  /*
   auto result = [](double a, double b){
      return a+b;
   }(10, 60);
   
   std::cout << "result " << [](double a, double b){
      return a+b;
   }(10, 60)
    << std::endl;
    */

    /*

    auto func1 = [](double a, double b){
      return a+b;
   };

   auto result1 = func1(23, 7);
   auto resutl2 = func1(9, 45);

   std::cout << "result1 :" << result1 << std::endl;
   std::cout << "result2 :" << resutl2 << std::endl;
   std::cout << "Direct Call :" << func1(50, 100.332) << std::endl;

   */

   // Explicitly specify the return type
   auto func3 = [](double a, double b)-> int{
      return a+b;
   };

   auto func4 = [](double a, double b){
      return a+b;
   };

   double a{6.9};
   double b{9.3};

   auto result3 = func3(a, b);
   auto result4 = func4(a, b);

   std::cout << "Result3 :" << result3 << std::endl;
   std::cout << "Result4 :" << result4 << std::endl;

   std::cout << "result3 :" << sizeof(result3) << std::endl; //4 bytes
   std::cout << "result4 :" << sizeof(result4) << std::endl; //8 bytes


   std::cout << "Done" << std::endl;


 }