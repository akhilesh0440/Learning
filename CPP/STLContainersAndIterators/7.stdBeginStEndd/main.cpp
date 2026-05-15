#include <iostream>
#include <vector>

int main(){
    // std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int vi[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Collection : ";

    for(auto it = std::begin(vi); it != std::end(vi); ++it){
        std::cout << *it << " ";
    }
}