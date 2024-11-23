#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Ham tao bang "bad character rule"
unordered_map<char, int> buildBadCharTable(const string &pattern)
{
    unordered_map<char, int> table;
    int m = pattern.length();
    for (int i = 0; i < m - 1; ++i)
        table[pattern[i]] = m - 1 - i;
    return table;
}

// Ham Boyer-Moore tim kiem chuoi con trong chuoi lon
vector<int> boyerMooreSearch(const string &text, const string &pattern)
{
    vector<int> result;
    int textLength = text.length();
    int patternLength = pattern.length();

    if (patternLength == 0)
        return result;
    unordered_map<char, int> badCharTable = buildBadCharTable(pattern);
    int s = 0;
    while (s <= textLength - patternLength)
    {
        int j = patternLength - 1;
        while (j >= 0 && pattern[j] == text[s + j])
            --j;
        if (j < 0)
        {
            result.push_back(s);
            s += (s + patternLength < textLength)
                     ? patternLength - badCharTable[text[s + patternLength]]
                     : 1;
        }
        else
        {
            s += max(1, badCharTable.count(text[s + j])
                            ? badCharTable[text[s + j]]
                            : patternLength);
        }
    }
    return result;
}

int main()
{
    string text = "mothaibabonnam";
    string pattern = "ba";
    vector<int> result = boyerMooreSearch(text, pattern);
    if (result.empty())
    {
        cout << "Khong tim thay chuoi con." << endl;
    }
    else
    {
        cout << "Chuoi con duoc tim thay tai cac vi tri: ";
        for (int idx : result)
        {
            cout << idx << " ";
        }
        cout << endl;
    }
    return 0;
}
