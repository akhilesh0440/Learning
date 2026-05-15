 #include <iostream>
 #include "cylinder.h"

 int main(){

  Cylinder cylinder1(10, 10); // Object
  cylinder1.volume();

  Cylinder *p_cylinder1 = &cylinder1;

  //  std::cout << "Volume : " << (*p_cylinder1).volume() << std::endl;
  std::cout << "Volume : " << p_cylinder1->volume() << std::endl;


  // Create a cylinder hear object through the new operator  
  Cylinder* p_cylinder2 = new Cylinder(100, 40);
  std::cout << "Volume (cylinder 2): " << p_cylinder2->volume() << std::endl;

   
 }