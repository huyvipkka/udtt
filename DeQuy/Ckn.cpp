#include<iostream>
using namespace std;

// C(n, k) = n! / (k!(n-k)!)
// C(n, k) = C(n-1, k-1) + C(n-1, k),  C(n, 0) = C(n, n) = 1

int C(int n, int k){
    if(k == 0 || k == n)
        return 1;
    return C(n-1, k-1) + C(n-1, k);
}

main(){
    cout << C(4, 2); // =6
}