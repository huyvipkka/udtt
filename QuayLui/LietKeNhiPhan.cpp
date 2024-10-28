#include <iostream>
using namespace std;

const int n = 3; // Độ dài của dãy nhị phân
int binary[n];   // Mảng lưu trữ dãy nhị phân hiện tại

void printBinary()
{
    for (int i = 0; i < n; i++)
    {
        cout << binary[i];
    }
    cout << endl;
}

void backtrack(int k)
{
    if (k == n)
    {
        printBinary();
        return;
    }

    binary[k] = 0;
    backtrack(k + 1);

    binary[k] = 1;
    backtrack(k + 1);
}

int main()
{
    backtrack(0);
    return 0;
}
