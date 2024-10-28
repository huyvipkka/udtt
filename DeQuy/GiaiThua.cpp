#include<iostream>
using namespace std;

int giaithua(int n){
    if(n <= 1) return 1;
    return n*giaithua(n-1);
}

main(){
    cout << giaithua(5);
}