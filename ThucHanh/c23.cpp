#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Pack
{
public:
    int m;
    int v;
    Pack(int m, int v)
    {
        this->m = m;
        this->v = v;
    }
};

// dp[i][j] là giá trị lớn nhất khi mà chọn đến gói hàng thứ i và khối lượng tối đa j
vector<vector<int>> knapsack(vector<Pack> &items, int M)
{
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (j < items[i - 1].m)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i - 1].m] + items[i - 1].v);
        }
    }
    return dp;
}

main()
{
    vector<Pack> items = {
        Pack(2, 3), Pack(3, 4), Pack(1, 4)};
    int M = 7;

    vector<vector<int>> res = knapsack(items, M);
    int n = items.size();
    cout << "v max = " << res[n][M] << endl;

    for (int i = n; i >= 0; i--)
    {
        if (res[i][M] != res[i - 1][M])
        {
            cout << "(" << items[i - 1].m << ", " << items[i - 1].v << ")" << endl;
            M -= items[i - 1].m;
        }
    }
}