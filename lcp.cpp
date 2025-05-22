#include<iostream>
#include<vector>
#include<string>

int main(){
    std::vector<std::string> vec = {"apple", "application", "appointment"};
    // find the longest common prefix
    std::string lcp = "";
    if(vec.size() == 0){
        std::cout << "No common prefix found" << std::endl;
        return 0;
    }
    for(int i = 0; i < vec[0].size(); i++){
        char c = vec[0][i];
        //std::cout << "Checking character: " << c << std::endl;
        //std::cout << "Checking index: " << i << std::endl;
        for(int j = 1; j < vec.size(); j++){
            if(i >= vec[j].size() || vec[j][i] != c){
                std::cout << "Longest common prefix: " << lcp << std::endl;
                return 0;
            }
        }
        lcp += c;
    }
}