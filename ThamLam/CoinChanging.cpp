#include <iostream>
using namespace std;
int Coins[10] = {100, 50, 20, 10, 5, 2, 1};
int n = 7; // length coins[]
int result[10];

bool CoinChanging(int tien)
{
    for (int i = 0; i < n; i++)
    {
        if (tien >= Coins[i])
        {
            result[i] = tien / Coins[i];
            tien = tien % Coins[i];
        }
        else
        {
            result[i] = 0;
        }
    }
    return tien == 0;
}

void Show()
{
    for (int i = 0; i < n; i++)
    {
        if (result[i] != 0)
            cout << result[i] << " * " << Coins[i] << endl;
    }
}

main()
{
    int tien = 45;
    if (CoinChanging(tien))
        Show();
    else
        cout << "K co phuong an";
}