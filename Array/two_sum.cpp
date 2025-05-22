#include<iostream>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int target = 6;

    int left = 0;
    int right = sizeof(arr) / sizeof(arr[0]) - 1;
    bool found = false;

    while(left < right){
        int sum = arr[left] + arr[right];
        if (sum == target){
            cout << "( " << left << " , " << right << " )";
            left++;
            right--;
            found = true;
        } else if ( sum < target) {
            left++;
        } else {
            right--;
        }
    }
    if (!found){
        cout << "No number avilabale";
    }
    
    return 0;
}