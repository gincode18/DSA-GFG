#include <iostream>
using namespace std;

int longest_substring_with_distinct_characters(string str)
{
    int n = str.length();
    int res = 0;
    int i = 0;
    vector<int> prevs(256, -1);
    for (int j = 0; j < n; j++)
    {
        i = max(i, prevs[str[j]] + 1);
        int maxEnd = j - i + 1;
        res = max(res, maxEnd);
        prevs[str[j]] = j;
    }

    return res;
}

int main()
{
    string str = "abcdabc";
    int res = longest_substring_with_distinct_characters(str);
    cout << res;
}