#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
Câu 2.1. Cho một số nguyên dương n ≥ 8, một dãy a gồm n số thực được sắp xếp theo
chiều tăng dần, một số thực C và 2 chuỗi P và Q không quá 255 ký tự chỉ gồm các chữ số,
chữ cái và dấu cách. Cài đặt chương trình thực hiện:
- Cài đặt thuật toán tham lam để tính D là số lượng phần tử nhiều nhất có thế lấy
trong dãy a để được một giá trị M không vượt quá C và cho biết giá trị của các phần
tử đã lấy trong a (nếu có). Cài đặt thuật toán Boyer Moore Horspool cho biết chuỗi
ký tự Q có phải là một chuỗi con của chuỗi ký tự P hay không?
 */

int ThamLam(float a[], int n, float c)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= c)
        {
            c -= a[i];
            dem++;
        }
        else
        {
            break;
        }
    }
    return dem;
}

unordered_map<char, int> buildBadCharTable(const string &pattern)
{
    unordered_map<char, int> table;
    int m = pattern.length();
    for (int i = 0; i < m - 1; ++i)
        table[pattern[i]] = m - 1 - i;
    return table;
}

int Boyer(string text, string pattern)
{
    int txtLen = text.length();
    int ptLen = pattern.length();
    unordered_map<char, int> shift = buildBadCharTable(pattern);

    for (int i = 0; i < txtLen - ptLen;)
    {
        int j = ptLen - 1;
        while (j >= 0 && text[i + j] == pattern[j])
            j--;

        if (j < 0)
            return i;
        else
        {
            if (!shift.count(text[i + j]))
                i += ptLen;
            else
                i += max(1, shift[text[i + j]]);
        }
    }
    return -1;
}

main()
{
    float a[8] = {1.2, 2.5, 3.6, 4.8, 5.1, 6.4, 7.7, 8.9};
    float c = 14.3;
    int n = ThamLam(a, 8, c);
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    string text = "Viet nam vo dich";
    string pattern = "nam";
    cout << Boyer(text, pattern);
}