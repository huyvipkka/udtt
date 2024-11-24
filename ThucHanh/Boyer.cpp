#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> Shift(string pattern)
{
    unordered_map<char, int> map;
    int n = pattern.length();
    for (int i = 0; i < n; i++)
    {
        map[pattern[i]] = n - i - 1;
    }
    return map;
}

int boyerMooreSearch(const string &text, const string &pattern)
{
    int ptLength = pattern.length();
    int txtLength = text.length();
    if (txtLength == 0 || ptLength > txtLength)
        return -1;

    unordered_map<char, int> map = Shift(pattern);
    for (int i = 0; i <= txtLength - ptLength;)
    {
        int j = ptLength - 1;
        while (j >= 0 && pattern[j] == text[i + j])
            j--;

        if (j < 0)
            return i;
        else
        {
            if (!map.count(text[i + j]))
                i += ptLength;
            else
                i += max(1, map[text[i + j]]);
        }
    }
    return -1;
}

main()
{
    string text = "mot hai ba";
    string pattern = "h";
    cout << boyerMooreSearch(text, pattern);
}