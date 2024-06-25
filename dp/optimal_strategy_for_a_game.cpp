#include <iostream>
using namespace std;

int optimal_strategy_for_a_game_naive(int arr[], int n, int i, int j)
{
    if (i + 1 == j)
    {
        return max(arr[i], arr[j]);
    }
    return max(arr[i] + min(optimal_strategy_for_a_game_naive(arr, n, i + 2, j), optimal_strategy_for_a_game_naive(arr, n, i + 1, j - 1)),
               arr[j] + min(optimal_strategy_for_a_game_naive(arr, n, i, j - 2), optimal_strategy_for_a_game_naive(arr, n, i + 1, j - 1)));
}

int optimal_strategy_for_a_game(int arr[], int n)
{   // we fill dp[][] diaggnolly and alternatively
    // the result is stored in uppper right corner of dp[][]

    int dp[n][n];
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }
    for (int gap = 3; gap < n; gap += 2)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]));
        }
    }

    return dp[0][n - 1];
}

int main()
{
    int arr[] = {20, 5, 4, 6};
    int n = sizeof(arr) / sizeof(int);
    int res = optimal_strategy_for_a_game_naive(arr, n, 0, n - 1);
    cout << res << " ";
    res = optimal_strategy_for_a_game(arr, n);
    cout << res << " ";
    return 0;
}