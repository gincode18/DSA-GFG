#include <iostream>
using namespace std;

int zero_one_knapsack_naive(int v[], int w[], int n, int W)
{
    if (W == 0 || n == 0)
    {
        return 0;
    }
    if (w[n - 1] > W)
    {
        return zero_one_knapsack_naive(v, w, n - 1, W);
    }
    else
    {
        return max(zero_one_knapsack_naive(v, w, n - 1, W), v[n - 1] + zero_one_knapsack_naive(v, w, n - 1, W - w[n - 1]));
    }
}

int zero_one_knapsack(int v[], int w[], int n, int W)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= W; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {

            if (w[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int v[] = {10, 40, 30, 50};
    int w[] = {5, 4, 6, 3};
    int W = 10;
    int n = sizeof(v) / sizeof(int);
    int res = zero_one_knapsack_naive(v, w, n, W);
    cout << res << " ";
    res = zero_one_knapsack(v, w, n, W);
    cout << res << " ";
    return 0;
}