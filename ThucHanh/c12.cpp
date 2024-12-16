#include <iostream>
using namespace std;
/*
Câu 1.2. Viết chương trình gồm các yêu cầu sau:
- Khởi tạo một số nguyên dương n ≥ 10 và 1 mảng a gồm n số nguyên.
- Cài đặt một thuật toán tính tổng tất cả các số lẻ trong mảng a theo chiến lược đệ
qui. Ứng dụng thuật toán và hiển thị kết quả lên màn hình.
*/

int sumOdd(int a[], int l, int r)
{
    if (l >= r)
        return a[l] % 2 == 0 ? 0 : a[l];
    int m = (l + r) / 2;
    return sumOdd(a, l, m) + sumOdd(a, m + 1, r);
}

main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sumOdd(a, 0, 9);
}