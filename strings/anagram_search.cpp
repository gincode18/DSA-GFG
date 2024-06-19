#include <iostream>
#include <unordered_map>
#define CHAR 256

using namespace std;

bool issame(int p[], int t[])
{
    for (int i = 0; i < CHAR; i++)
    {
        if (p[i] != t[i])
        {
            return false;
        }
    }
    return true;
}
int anagram_search(string txt, string pat)
{
    int p[CHAR] = {0};
    int t[CHAR] = {0};
    for (int i = 0; i < pat.length(); i++)
    {
        p[(int)pat[i]] += 1;
        t[(int)txt[i]] += 1;
    }
    for (int i = pat.length(); i <= txt.length(); i++)
    {
        if (issame(p, t))
            return true;
        t[(int)txt[i]] += 1;
        t[(int)txt[i - pat.length()]] -= 1;
    }

    return false;
}

int main()
{
    string txt = "halvsi";
    string pat = "vis";
    bool res = anagram_search(txt, pat);
    cout << res;
    return 0;
}