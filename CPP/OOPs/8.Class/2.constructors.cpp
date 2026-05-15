 #include<iostream>

 const double PI {3.14159};

 class Cylinder {
   
   public:
      Cylinder(){

      }
      // Constructors
      /* Cylinder(){
         base_radius = 2.0;
         height = 2.0;
      }

      Cylinder(double rad_parm, double height_param){
         base_radius = rad_parm;
         height = height;
      } */
      // Function (Method)
      double volume(){
         return PI * base_radius * base_radius * height;
      }
   
   private:   
      // Member variables
      double base_radius {1};
      double height {1};
 };
 
 int main(){

   Cylinder cylinder1; // Object
   // Cylinder cylinder1(10, 4); // Object
   std::cout << "volume : " << cylinder1.volume() << std::endl;  

   return 0;  
 }