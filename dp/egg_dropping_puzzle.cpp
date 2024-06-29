#include <iostream>
using namespace std;

int egg_dropping_puzzle_naive(int n, int f)
{
    if (f == 0 || f == 1)
    {
        return f;
    }
    if (n == 1)
    {
        return f;
    }
    int min_val = INT_MAX, res;
    for (int i = 1; i <= f; i++)
    {
        res = max(egg_dropping_puzzle_naive(n - 1, i - 1), egg_dropping_puzzle_naive(n, f - i));
        min_val = min(res, min_val);
    }

    return min_val + 1;
}

int egg_dropping_puzzle(int n, int f)
{
    int dp[f + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = 0;
        dp[1][i] = 1;
    }
    for (int i = 1; i <= f; i++)
    {
        dp[i][1] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= f; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= i; x++)
            {
                int res = max(dp[x - 1][j - 1], dp[i - x][j]) + 1;
                dp[i][j] = min(dp[i][j], res);
            }
        }
    }
    return dp[n][f];
}

int main()
{
    int n = 2, f = 10;
    int res = egg_dropping_puzzle_naive(n, f);
    cout << res << " ";
    res = egg_dropping_puzzle(n, f);
    cout << res << " ";

    return 0;
}