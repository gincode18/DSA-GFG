#include <iostream>
using namespace std;

int improved_naive_pattern_searching_for_distinct(string txt, string pat)
{
    int n = txt.length();
    int m = pat.length();
    for (int i = 0; i < n;)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (pat[j] != txt[i + j])
            {
                break;
            }
        }
        if (j == m)
        {
            cout << i << " ";
        }
        if (j == 0)
        {
            i++;
        }
        else
        {
            i = i + j;
        }
    }

    return 0;
}

int main()
{
    string txt = "vishalvishalvishal";
    string pat = "vis";
    improved_naive_pattern_searching_for_distinct(txt, pat);
    return 0;
}