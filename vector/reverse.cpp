#include<iostream>
#include<vector>

// function to perform the reverse operation of a vector
std::vector<int> reverse(std::vector<int>& vec){
    std::vector<int> reversed;
    for(int i = vec.size() -1; i >=0; i--){
        reversed.push_back(vec[i]);
    }
    return reversed;
}

int main() {
    std:: vector<int> vec = {12, 40, 33, 1, 5, -15};
    std::vector<int> reversed = reverse(vec);
    for(int i: reversed){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}