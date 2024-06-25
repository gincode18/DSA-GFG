#include <iostream>
using namespace std;

int minimum_jumps_to_reach_at_end_naive(int arr[], int n)
{
    if (n == 1)
    {
        return 0;
    }

    int res = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] + i >= n - 1)
        {
            int sub_res = minimum_jumps_to_reach_at_end_naive(arr, i + 1);
            if (sub_res != INT_MAX)
            {
                res = min(res, sub_res + 1);
            }
        }
    }

    return res;
}

int minimum_jumps_to_reach_at_end(int arr[], int n)
{
    int dp[n - 1];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] + j >= i)
            {
                if (dp[j] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    return dp[n - 1];
}
int main()
{
    int arr[] = {3, 4, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    int res = minimum_jumps_to_reach_at_end_naive(arr, n);
    cout << res << " ";
    res = minimum_jumps_to_reach_at_end(arr, n);
    cout << res << " ";
    return 0;
}