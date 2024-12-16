#include <iostream>
using namespace std;
/*
Câu 1.1. Viết chương trình gồm các yêu cầu sau:
- Khởi tạo một số nguyên dương n ≥ 10 và 1 mảng a gồm n số thực.
- Cài đặt một thuật toán tính tổng tất cả các số trong mảng a theo chiến lược chia để
trị. Ứng dụng thuật toán và hiển thị kết quả lên màn hình.
 */
float sum(float a[], int l, int r)
{
    if (l >= r)
        return a[l];
    int m = (l + r) / 2;
    float sumLeft = sum(a, l, m);
    float sumRight = sum(a, m + 1, r);
    return sumLeft + sumRight;
}

main()
{
    float a[] = {1.5, 4.2, 0.3, 9.5, 3.7};
    int n = sizeof(a) / sizeof(a[0]);
    cout << sum(a, 0, n - 1);
}
