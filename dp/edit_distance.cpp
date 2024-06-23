#include <iostream>
#include <string.h>
using namespace std;

int edit_distance_naive(string str1, string str2, int m, int n)
{
    if (m == 0)
    {
        return n;
    }

    if (n == 0)
    {
        return m;
    }
    if (str1[m - 1] == str2[n - 1])
    {
        return edit_distance_naive(str1, str2, m - 1, n - 1);
    }
    else
    {
        return 1 + min(edit_distance_naive(str1, str2, m, n - 1),
                       min(edit_distance_naive(str1, str2, m - 1, n),
                           edit_distance_naive(str1, str2, m - 1, n - 1)));
    }
}

int edit_distance(string str1, string str2, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i][j - 1],
                                   min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string str1 = "intention";
    string str2 = "execution";
    int res = edit_distance_naive(str1, str2, str1.length(), str2.length());
    cout << res << " ";
    res = edit_distance(str1, str2, str1.length(), str2.length());
    cout << res;
    return 0;
}