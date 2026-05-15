#include <iostream>
#include <vector>

int main(){
    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int>::reverse_iterator it = numbers.rbegin();

    std::cout << "Numbers : [";
    while(it != numbers.rend()-1){
        std::cout << *it << ", ";
        it++;
    }
    std::cout << *it << "]" << std::endl;

/*     std::cout << "--------------------" << std::endl;
    if(it != numbers.end()){
        std::cout << "Do something...." << std::endl;
    }
 */
}