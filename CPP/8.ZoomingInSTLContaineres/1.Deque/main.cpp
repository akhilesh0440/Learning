#include <iostream>
#include <deque>

class Item{
public : 
    Item() :m_var(0){
        std::cout << "Item default constructor called" << std::endl;
    }
    Item(int var) : m_var(var){
       // std::cout << "Item constructor called for: " << m_var << std::endl;
    }
    
    Item(const Item& source) : m_var{source.m_var}{
        //std::cout << "Item copy constructor called for :" << m_var << std::endl;
    }
    
    int get() const{
        return m_var;
    }
private : 
    int m_var{0};
};

std::ostream& operator << (std::ostream& out, const Item & item){
    out << "Item [ value : " << item.get() << "]";
    return out;
}

template <typename T>
void print_collection(const T& collection){
    
    auto it = collection.begin();
    
    std::cout << " Collection [";
    while(it != collection.end()){
        std::cout << " " << *it ;
        ++it;
    }
    std::cout << "]" << std::endl;
}



int main(){

    //Creating deques
    std::deque<int> numbers = {1,2,3,4,5,6};
    std::deque<Item> items {Item(22), Item(33), Item(44), Item(55)};

    std::cout << "numbers: ";
    print_collection(numbers);
    
    std::cout << "items: ";
    print_collection(items);


    std::cout << std::endl;
    std::cout << "Elemetn access: " << numbers[3] << std::endl;
    std::cout << "numbers.at[3]: " << numbers.at(3) << std::endl; //bound check
    std::cout << "numbers[30] (undefined behavior): " << numbers[30] << std::endl; // no bound check
    // std::cout << "numbers.at(30) (throws exception)" << numbers.at(30) << std::endl; //exception bounc check
    
    std::cout << "numbers.front(): " << numbers.front() << std::endl;
    std::cout << "numbers.back(): " << numbers.back() << std::endl;

    std::cout << "---------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Iterators: " << std::endl;
    auto it = numbers.begin();

    std::cout << "Deque(with iterators): [";
    while(it != numbers.end()){
        std::cout << *it << " " ;
        ++it;
    }
    std::cout << "]" << std::endl;

    // reverse iterator 
    std::cout << "---------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Iterators: " << std::endl;
    auto it_reverse = numbers.rbegin();

    std::cout << "Deque(Reverse raversal with iterators): [";
    while(it_reverse != numbers.rend()){
        std::cout << *it_reverse << " " ;
        ++it_reverse;
    }
    std::cout << "]" << std::endl;


    // Capacity 
    std::cout << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Capacity: " << std::endl;
    std::cout << "numbers size: " << numbers.size() << std::endl;
    std::cout << "numbers max_size: " << numbers.max_size() << std::endl;
    std::cout << std::boolalpha;
    std::cout << "numers is empty: " << numbers.empty() << std::endl;

    numbers.push_back(20);
    std::cout << "after pushing 20 to back: " << std::endl;
    print_collection(numbers);
    std::cout << "numbers size: " << numbers.size() << std::endl;


    std::cout << "---------------------------------" << std::endl;
    // std::cout << "clear: " << std::endl;
    // numbers.clear();

    //Insert: element inserted in front of it_pos

    std::cout << std::endl;
    std::cout << "insert: " << std::endl;
    auto it_pos = numbers.begin() + 2;

    print_collection(numbers);

    numbers.insert(it_pos, 300);
    print_collection(numbers);
    numbers.insert(it_pos, 500);
    print_collection(numbers);

    std::cout << "---------------------------------" << std::endl;
    // emplace 
    std::cout << std::endl;
    std::cout << "Emplace: " << std::endl;

    print_collection(numbers);

    auto it_emplace = numbers.begin() + 2;
    numbers.emplace(it_emplace, 57);
    print_collection(numbers);


    // Erase 
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Erase: " << std::endl;

    print_collection(numbers);
    numbers.erase(numbers.begin() + 4); //erase in particular location

    print_collection(numbers);

    numbers.erase(numbers.begin()+1, numbers.begin()+3);;
    print_collection(numbers);

    // add to back 
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Erase: " << std::endl;

    print_collection(numbers);
    numbers.emplace_back(4);
    numbers.emplace_back(44);
    numbers.emplace_back(444);

    print_collection(numbers);
    

    // Erase 
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Erase: " << std::endl;

    print_collection(numbers);
    numbers.erase(numbers.begin() + 4); //erase in particular location

    print_collection(numbers);

    numbers.erase(numbers.begin()+1, numbers.begin()+3);;
    print_collection(numbers);

    // Resize 
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Resize: " << std::endl;
    std::cout << "Resize (before): " << std::endl;

    print_collection(numbers);
    std::cout << "numbers size: "  << numbers.size() << std::endl;

    std::cout << std::endl;
    numbers.resize(30);
    print_collection(numbers);
    std::cout << "numbers size(after resize to 30): "  << numbers.size() << std::endl;
    
    std::cout << std::endl;
    numbers.resize(10);
    print_collection(numbers);
    std::cout << "numbers size(after resize to 10): "  << numbers.size() << std::endl;
     
    
    // Swap 
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Swap: " << std::endl;
    std::deque <Item> other_items = {Item(100), Item(200), Item(300)};

    std::cout << "items: ";
    print_collection(items);
        
    std::cout << "other items: ";
    print_collection(other_items);

    other_items.swap(items);
    
    std::cout << "items(after swap): ";
    print_collection(items);
        
    std::cout << "other items(after swap).: ";
    print_collection(other_items);
    
    return 0;
}