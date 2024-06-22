#include <iostream>
using namespace std;

vector<vector<int>> memo;

void initializeMemo(int rows, int cols, int value)
{
    memo = vector<vector<int>>(rows, vector<int>(cols, value));
}

int longest_common_subsequence_memoization(string str1, string str2, int n, int m)
{
    if (memo[n][m] == -1)
    {
        if (n == 0 || m == 0)
        {
            return memo[n][m] = 0;
        }
        if (str1[n - 1] == str2[m - 1])
        {
            memo[n][m] = 1 + longest_common_subsequence_memoization(str1, str2, n - 1, m - 1);
        }
        else
        {
            memo[n][m] = max(longest_common_subsequence_memoization(str1, str2, n - 1, m), longest_common_subsequence_memoization(str1, str2, n, m - 1));
        }
    }

    return memo[n][m];
}

int longest_common_subsequence_tabulation(string str1, string str2, int n, int m)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string str1 = "XMJYAUZ";
    string str2 = "MZJAWXU";

    int rows = 100;
    int cols = 100;
    initializeMemo(rows, cols, -1);

    int res = longest_common_subsequence_memoization(str1, str2, str1.length(), str2.length());
    cout << res << " ";

    res = longest_common_subsequence_tabulation(str1, str2, str1.length(), str2.length());
    cout << res;
    return 0;
}