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

int tknp(int a[], int l, int r, int search)
{
    if (l > r)
    {
        return -1;
    }

    int m = (l + r) / 2;
    if (a[m] == search)
        return m;
    else if (a[m] < search)
        return tknp(a, m + 1, r, search);
    else
        return tknp(a, l, m - 1, search);
}

main()
{
    int a[] = {5, 2, 1, 9, 8, 3, 6};
    int n = sizeof(a) / sizeof(a[0]);
    QuickSort(a, 0, n - 1);
    printArray(a, n);
    cout << tknp(a, 0, n - 1, 8);
}