 #include<iostream>

 const double PI {3.14159};

 class Cylinder {
   
   public:
      Cylinder() = default; //default constructor
      // Constructors 
      Cylinder(double rad_parm, double height_param){
         base_radius = rad_parm;
         height = height;
      }
      // Function (Method)
      double volume(){
         return PI * base_radius * base_radius * height;
      }
      
      // Setter and getters 
      double get_base_radius(){
         return base_radius;
      }

      double get_height(){
         return height;
      }

      void set_base_radius(double rad_param){
         base_radius = rad_param;
      }

      void set_height(double rad_param){
         height = rad_param;
      }
   
   private:   
      // Member variables
      double base_radius {1};
      double height {1};
 };
 
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



   return 0;  
 }