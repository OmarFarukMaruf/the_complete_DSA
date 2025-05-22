#include<iostream>
#include<vector>

// linear search using vector
int main() {
    std::vector<int> vec = {12, 40, 33, 1, 5, -15};
    int key = 33;
    bool found = false;
    for( int i: vec){
        if(i == key){
            found = true;
            break;
        }
    }
    if(found){
        std::cout << "Key found in the vector" << std::endl;
    } else {
        std::cout << "Key not found in the vector" << std::endl;
    }
    return 0;
}