#include <iostream>
using namespace std;

int a[] = {1, 2, 3, 4, 5};
int n = 5; // kich thuoc mang a
int m = 3; // kich thuoc tap con cua a
int temp[20];

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}

void backtrack(int start, int k)
{
    if (k == m)
    {
        printArray(temp, m);
        return;
    }
    for (int i = start; i < n; i++)
    {
        temp[k] = a[i];
        backtrack(i + 1, k + 1);
    }
}

main()
{
    backtrack(0, 0);
}