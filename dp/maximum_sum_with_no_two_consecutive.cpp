#include <iostream>
using namespace std;

int maximum_sum_with_no_two_consecutive_naive(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }

    if (n == 2)
    {
        return max(arr[0], arr[1]);
    }

    return max(maximum_sum_with_no_two_consecutive_naive(arr, n - 1),
               arr[n - 1] + maximum_sum_with_no_two_consecutive_naive(arr, n - 2));
}

int maximum_sum_with_no_two_consecutive(int arr[], int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
    }

    return dp[n - 1];
}
int main()
{
    int arr[] = {10, 5, 15, 20};
    int n = sizeof(arr) / sizeof(int);
    int res = maximum_sum_with_no_two_consecutive_naive(arr, n);
    cout << res << " ";
    res = maximum_sum_with_no_two_consecutive(arr, n);
    cout << res << " ";
    return 0;
}