#include <iostream>
using namespace std;
int results[20];
// f(0) = 1, f(1) = 1, f(2) = 2, 3, 5, 8, 13
void fibo(int n)
{
    for (int i = 2; i <= n; i++)
    {
        results[i] = results[i - 1] + results[i - 2];
    }
}

main()
{
    results[0] = 1;
    results[1] = 1;
    int n = 5;
    fibo(n);
    cout << results[n];
}