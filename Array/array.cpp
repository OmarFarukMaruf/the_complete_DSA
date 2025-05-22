#include <iostream>
using namespace std;

int max_num(int arr[], int n){
    int index = 0;
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }
    return index;
}
int main() {

    int arr[] = {22, 3, -1, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum number is: " << max_num(arr, n);
}



