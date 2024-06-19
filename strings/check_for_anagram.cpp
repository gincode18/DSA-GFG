#include <iostream>
#include <unordered_map>
using namespace std;

bool check_for_anagram(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }
    unordered_map<char, int> map;
    for (int i = 0; i < str1.length(); i++)
    {
        map[str1[i]] += 1;
        map[str2[i]] -= 1;
    }
    for (auto pair : map)
    {
        if (pair.second != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string str1 = "aabca";
    string str2 = "acaba";
    bool res = check_for_anagram(str1, str2);
    cout << res;
    return 0;
}