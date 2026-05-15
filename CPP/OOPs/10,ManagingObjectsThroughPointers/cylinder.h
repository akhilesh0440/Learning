#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"

class Cylinder {
   
   public:
      Cylinder() = default; //default constructor
      // Constructors 
      Cylinder(double rad_parm, double height_param);
      // Function (Method)
      double volume();
      
      // Setter and getters 
      double get_base_radius();
      double get_height();
      void set_base_radius(double);
      void set_height(double);
   
   private:   
      // Member variables
      double base_radius {1};
      double height {1};
};

#endif