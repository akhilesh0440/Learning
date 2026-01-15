 #include<iostream>

 int max(int a, int b){
    std::cout << "Int overload code" << std::endl;
    return (a>b)? a:b;
 }

 int max(double a, double b){
    std::cout << "double overload code" << std::endl;
    return (a>b) ? a:b;
 }
 int main(){

    int x{4};
    int y{9};
    double a{5.4};
    double b{6.3};

    auto result = max(a, b);

 }