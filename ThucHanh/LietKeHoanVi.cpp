#include <iostream>
using namespace std;

int a[] = {1, 5, 3};
int used[20] = {false};
int n = sizeof(a) / sizeof(a[0]);
int temp[20];

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}

void backtrack(int k)
{
    if (k == n)
    {
        printArray(temp, n);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            temp[k] = a[i];
            backtrack(k + 1);
            used[i] = false;
        }
    }
}

main()
{
    backtrack(0);
}