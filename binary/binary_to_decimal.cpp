#include<iostream>
#include<cmath>
using namespace std;


int decimal_to_binary(int n){
    int ans = 0, p = 0;
    while(n>0){
        int mul = n%10;
        n /= 10;
        ans += mul*(pow(2,p));
        p++;
    }
    return ans;
}
int main()
{
    int n = 1001;
    cout<<decimal_to_binary(n);
    return 0;
}