#include <iostream>
using namespace std;

int a[] = {1, 2, 5};              // Mảng ban đầu
int n = sizeof(a) / sizeof(a[0]); // Kích thước của mảng
bool used[5] = {false};           // Mảng đánh dấu các phần tử đã sử dụng
int perm[5];                      // Mảng lưu trữ hoán vị hiện tại
// Hàm in hoán vị hiện tại
void printPermutation()
{
    for (int i = 0; i < n; i++)
    {
        cout << perm[i] << " ";
    }
    cout << endl;
}
// Hàm quay lui để liệt kê các hoán vị
void backtrack(int k)
{
    if (k == n)
    {
        printPermutation(); // Nếu đã chọn đủ n phần tử, in hoán vị
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            perm[k] = a[i];   // Đặt phần tử a[i] vào vị trí k của hoán vị
            used[i] = true;   // Đánh dấu phần tử này đã được sử dụng
            backtrack(k + 1); // Gọi đệ quy cho vị trí tiếp theo
            used[i] = false;  // Bỏ đánh dấu để thử phần tử khác
        }
    }
}

int main()
{
    backtrack(0); // Bắt đầu từ vị trí đầu tiên trong hoán vị
    return 0;
}
