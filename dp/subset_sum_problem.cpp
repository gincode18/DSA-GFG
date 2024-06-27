#include <iostream>
using namespace std;

int subset_sum_problem_naive(int arr[], int n, int sum)
{

    if (sum == 0)
    {
        return 1;
    }

    if (n == 0)
    {
        return 0;
    }
    if (arr[n - 1] > sum)
    {
        return subset_sum_problem_naive(arr, n - 1, sum);
    }

    return subset_sum_problem_naive(arr, n - 1, sum) + subset_sum_problem_naive(arr, n - 1, sum - arr[n - 1]);
}

int subset_sum_problem(int arr[], int n, int sum)
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
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    int arr[] = {10, 5, 2, 3, 6};
    int sum = 8;
    int n = sizeof(arr) / sizeof(int);
    int res = subset_sum_problem_naive(arr, n, sum);
    cout << res << " ";
    res = subset_sum_problem(arr, n, sum);
    cout << res << " ";
    return 0;
}
