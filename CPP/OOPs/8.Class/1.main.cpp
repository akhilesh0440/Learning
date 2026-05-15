 #include<iostream>

 const double PI {3.14159};

 class Cylinder {
   
   public:
      double volume(){
         return PI * base_radius * base_radius * height;
      }
   
   public:   
      // Member variables
      double base_radius {1};
      double height {1};
 };
 
 int main(){

   Cylinder cylinder1;
   std::cout << "volume : " << cylinder1.volume() << std::endl;  
   std::cout << "base_radius : " << cylinder1.base_radius << std::endl;
   std::cout << "height : " << cylinder1.height << std::endl;

   // Change the member variables
   cylinder1.base_radius = 10;
   cylinder1.height = 11;

   std::cout << "volume : " << cylinder1.volume() << std::endl;  
   std::cout << "base_radius : " << cylinder1.base_radius << std::endl;
   std::cout << "height : " << cylinder1.height << std::endl;


   
 }