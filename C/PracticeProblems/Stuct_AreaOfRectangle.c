// The following structures are desinged to store information about objects on a graphical screen:

// struct point { it x, y};
// struct recatangle{ struct point upper_left, lower_right; };

// A point sturcture stores the x and y corrdinates of a point on the screen.
// A rectangle structures stores the coordinates of the upper left and lower right
// corners of the recatangle.

// Writa a function that accepts rectangle structure r as an argument and computes the area of r.

#include<stdio.h>

struct point
{
    int x;
    int y;
};

struct rectangle
{
    struct point upper_left;
    struct point lower_right;
    
} rect;

int main(){
    printf("Enter the coordinates of the upper left\n");
    scanf("%d%d", rect.upper_left.x, rect.upper_left.y);
    printf("Enter the coordinates of the lower right\n");
    scanf("%d%d", rect.lower_right.x, rect.lower_right.y);

    int length = rect.lower_right.x - rect.upper_left.x;
    int breadth = rect.upper_left.y - rect.lower_right.y;

    int area = length*breadth;

    printf("Area of the rectangle is %dcm", area);
    return 0;
}
