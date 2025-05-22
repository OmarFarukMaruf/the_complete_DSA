#include<iostream>
using namespace std;

// Sum of all digits of a number
/*
int sumOfDigits(int n){
    if(n == 0){
        return 0;
    }
    return n%10 + sumOfDigits(n/10);
}

int main(){
    int n;
    cin>>n;
    cout<<sumOfDigits(n);
    return 0;
}
*/


// Calculation of nCr
int fact(int n){
    if(n == 0){
        return 0;
    } return n*fact(n-1);
}

int nCr(int n, int r){
    int num, den;
    num = fact(n);
    den = fact(r)*fact(n-r);
    return num/den;
}

int main(){
    int n, r;
    cin>>n>>r;
    cout<<nCr(n, r);
    return 0;
}

