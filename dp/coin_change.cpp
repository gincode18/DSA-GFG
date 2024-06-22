#include <iostream>
using namespace std;
// using recursion
int coin_change_naive(int coin[], int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }

    if (n == 0)
    {
        return 0;
    }

    if (sum < 0)
    {
        return 0;
    }

    return coin_change_naive(coin, n, sum - coin[n - 1]) + coin_change_naive(coin, n - 1, sum);
}
// using dp
int coin_change(int coin[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coin[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int coin[] = {2, 5, 3};
    int sum = 5;
    int n = sizeof(coin) / sizeof(int);
    int res = coin_change_naive(coin, n, sum);
    cout << res << " ";
    res = coin_change(coin, n, sum);
    cout << res << " ";

    return 0;
}