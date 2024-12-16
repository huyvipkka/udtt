#include <iostream>
#include <vector>
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
vector<int> knapsack(vector<Pack> &items, int M)
{
    vector<int> dp(M + 1, 0);
    for (int i = 0; i < items.size(); i++)
    {
        for (int w = M; w >= items[i].m; w--)
        { // Duyệt từ M xuống items[i].m để tránh tính lại gói hàng này
            dp[w] = max(dp[w], dp[w - items[i].m] + items[i].v);
        }
    }
    return dp;
}

main()
{
    vector<Pack> items = {
        Pack(2, 3), Pack(3, 4), Pack(1, 4)};
    int M = 7;

    vector<int> res = knapsack(items, M);
    cout << res[M] << endl;

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    int w = M;
    cout << "Selected items:" << endl;
    for (int i = items.size() - 1; i >= 0; i--) // Duyệt ngược qua các gói hàng
    {
        if (w >= items[i].m && res[w] == res[w - items[i].m] + items[i].v)
        {
            cout << "(" << items[i].m << ", " << items[i].v << ")" << endl;
            w -= items[i].m; // Giảm khối lượng còn lại
        }
    }
}