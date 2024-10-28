#include <iostream>
using namespace std;

int temp[20];

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}

void backtrack(int n, int k)
{
    if (k == n)
    {
        printArray(temp, n);
        return;
    }
    temp[k] = 0;
    backtrack(n, k + 1);

    temp[k] = 1;
    backtrack(n, k + 1);
}

main()
{
    backtrack(3, 0);
}