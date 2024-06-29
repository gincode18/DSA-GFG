#include <iostream>
using namespace std;

int sum(int arr[], int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int allocate_minimum_pages_naive(int arr[], int n, int k)
{
    if (k == 1)
    {
        return sum(arr, 0, n - 1);
    }
    if (n == 1)
    {
        return arr[0];
    }
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        res = min(res, max(allocate_minimum_pages_naive(arr, i, k - 1), sum(arr, i, n - 1)));
    }

    return res;
}

int allocate_minimum_pages(int arr[], int n, int k)
{
    int dp[k + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = sum(arr, 0, i - 1);
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = arr[0];
    }
    for (int i = 2; i <= k; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            for (int p = 2; p < j; p++)
            {
                dp[i][j] = INT_MAX;
                dp[i][j] = min(dp[i][j], max(dp[i - 1 ][p], sum(arr, p, j - 1)));
            }
        }
    }
    return dp[k][n];
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;
    int res = allocate_minimum_pages_naive(arr, n, k);
    cout << res << " ";
    res = allocate_minimum_pages(arr, n, k);
    cout << res << " ";
    return 0;
}