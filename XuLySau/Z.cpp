#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> Z(const string &pattern, const string &text)
{
    string s = pattern + "$" + text;
    int n = s.length();
    vector<int> z(n);

    for (int i = 1; i < n; i++)
    {
        while (i + z[i] < n && s[z[i]] == s[z[i] + i])
            z[i]++;
    }
    return z;
}

main()
{
    string pattern = "Viet";
    string text = "o Viet Nam Viet Tay";
    vector<int> result = Z(pattern, text);
    for (int e : result)
    {
        cout << e << " ";
    }
    cout << endl;
    for (int i = 1; i < result.size(); i++)
    {
        if (result[i] == pattern.length())
        {
            cout << i - 1 - pattern.length() << " ";
        }
    }
}