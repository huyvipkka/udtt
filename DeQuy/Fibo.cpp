#include<iostream>
using namespace std;
// 1 1 2 3 5
int fibo(int n){
    if(n <= 2) return 1;
    return fibo(n-1) + fibo(n-2);
}

main(){
    cout << fibo(5);
}