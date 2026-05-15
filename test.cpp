#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    cin >> n >> q;
    std::vector<string> hrml_tags;
    for(int i=0; i<n; i++){
        char *input;
        cin >> input;
        hrml_tags.push_back(input);                
    }
    return 0;
}
