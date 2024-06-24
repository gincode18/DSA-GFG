#include <iostream>
using namespace std;

int maximum_cuts_naive(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1;
    }
    int res = 1 + max(maximum_cuts_naive(n - a, a, b, c),
                      max(maximum_cuts_naive(n - b, a, b, c), maximum_cuts_naive(n - c, a, b, c)));
    if (res == 0)
    {
        return -1;
    }

    return res;
}

int maximum_cuts(int n, int a, int b, int c)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
        if (i - a >= 0)
        {
            dp[i] = max(dp[i], dp[i - a]);
        }

        if (i - b >= 0)
        {
            dp[i] = max(dp[i], dp[i - b]);
        }

        if (i - c >= 0)
        {
            dp[i] = max(dp[i], dp[i - c]);
        }
        if (dp[i] != -1)
        {
            dp[i]++;
        }
    }
    return dp[n];
}

int main()
{
    int n = 5, a = 1, b = 2, c = 3;
    int res = maximum_cuts_naive(n, a, b, c);
    cout << res << " ";
    res = maximum_cuts(n, a, b, c);
    cout << res << " ";
    return 0;
}