#include <iostream>
using namespace std;

int naive_pattern_searching(string txt, string pat)
{
    int n = txt.length();
    int m = pat.length();
    for (int i = 0; i < n; i++)
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
    }

    return 0;
}

int main()
{
    string txt = "vishalvishalvishal";
    string pat = "vis";
    naive_pattern_searching(txt, pat);
    return 0;
}