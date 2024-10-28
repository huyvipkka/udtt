#include <iostream>
using namespace std;
// 1 1 2 3 5
int ucln(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return ucln(b, a % b);
}

main()
{
    cout << ucln(12, 8);
}