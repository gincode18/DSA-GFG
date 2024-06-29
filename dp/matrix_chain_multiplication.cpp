#include <iostream>
using namespace std;

int matrix_chain_multiplication_naive(int arr[], int i, int j)
{
    if (i + 1 == j)
    {
        return 0;
    }
    int res = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        res = min(matrix_chain_multiplication_naive(arr, k, j) +
                      matrix_chain_multiplication_naive(arr, i, k) +
                      arr[i] * arr[j] * arr[k],
                  res);
    }
    return res;
}

int matrix_chain_multiplication(int arr[], int n)
{
    int dp[n][n];
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = 0;
    } 

    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = gap + i;
            dp[i][j] = INT_MAX;
 
            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[k][j] +
                                             dp[i][k] +
                                             arr[i] * arr[k] * arr[j]);
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    int arr[] = {2, 1, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    int res = matrix_chain_multiplication_naive(arr, 0, n - 1);
    cout << res << " ";
    res = matrix_chain_multiplication(arr, n);
    cout << res << " ";
    return 0;
}