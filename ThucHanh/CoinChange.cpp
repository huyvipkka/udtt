#include <iostream>
#include <vector>
#include <algorithm>

#define INT_MAX 9999
using namespace std;

vector<int> CoinChange(vector<int> coins, int tien)
{
    vector<int> res(tien + 1, INT_MAX);
    res[0] = 0;
    for (int i = 1; i <= tien; i++)
    {
        for (int coin : coins)
        {
            if (i >= coin && res[i - coin] != INT_MAX)
            {
                res[i] = min(res[i], res[i - coin] + 1);
            }
        }
    }
    return res;
}

main()
{
    vector<int> Coins = {50, 20, 10, 5, 2};
    vector<int> res = CoinChange(Coins, 12);
    for (int i : res)
    {
        cout << i << " ";
    }
}