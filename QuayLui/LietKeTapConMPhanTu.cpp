#include <iostream>
using namespace std;

int array[5] = {1, 3, 5, 6, 9};
int n = 5;       // Kích thước của mảng
int subset[100]; // Mảng lưu trữ tập con hiện tại
int m = 3;       // Kích thước của tập con

// Hàm in tập con hiện tại
void printSubset(int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << subset[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

// Hàm quay lui để tạo tập con
void backtrack(int start, int k)
{
    if (k == m)
    {
        printSubset(m);
        return;
    }

    for (int i = start; i < n; i++)
    {
        subset[k] = array[i];
        backtrack(i + 1, k + 1);
    }
}

int main()
{
    backtrack(0, 0); // Bắt đầu từ phần tử đầu tiên
    return 0;
}
