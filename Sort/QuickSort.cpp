#include <iostream>
using namespace std;

int partition(int a[], int l, int r)
{
    int pivot = a[r];
    int index = l;
    for (int i = l; i <= r; i++)
    {
        if (a[i] < pivot)
        {
            swap(a[i], a[index]);
            index++;
        }
    }
    swap(a[index], a[r]);
    return index;
}

void QuickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(a, l, r);
        QuickSort(a, l, pi - 1);
        QuickSort(a, pi + 1, r);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}

main()
{
    int a[8] = {4, 8, 3, 0, 5, 9, 2, 7};
    int n = 8;
    QuickSort(a, 0, n - 1);
    printArray(a, n);
}