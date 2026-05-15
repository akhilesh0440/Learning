 #include <iostream>
 #include "cylinder.h"

 int main(){

   Cylinder cylinder1; // Object
   // Cylinder cylinder1(10, 4); // Object
   std::cout << "Base radius: " << cylinder1.get_base_radius() << std::endl;  
   std::cout << "Height:  " << cylinder1.get_height() << std::endl;  

   // Modify attributes s
   cylinder1.set_base_radius(100);
   cylinder1.set_height(40);
   std::cout << "\nBase radius - setters: " << cylinder1.get_base_radius() << std::endl; 
   std::cout << "Height -setters:  " << cylinder1.get_height() << std::endl;  
   
 }