#include <iostream>
#include <climits>
using namespace std;

int Coins[10] = {100, 50, 20, 10, 5, 2};
int n = 6;

int CoinChanging(int tien)
{
    int dp[1001];
    for (int i = 0; i <= tien; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i <= tien; i++)
    {
        for (int coin : Coins)
        {
            if (i >= coin && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[tien] == INT_MAX)
        return -1;
    return dp[tien];
}

int main()
{
    int tien = 4;
    int result = CoinChanging(tien);

    if (result != -1)
        cout << "So dong xu it nhat: " << result << endl;
    else
        cout << "Khong co phuong an" << endl;
    return 0;
}
