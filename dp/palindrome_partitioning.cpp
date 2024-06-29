#include <iostream>
using namespace std;

bool is_palindrome(string str, int low, int high)
{

    while (low < high)
    {
        if (str[low] != str[high])
        {
            return false;
        }
        low++;
        high--;
    }
    return true;
}

int palindrome_partitioning_naive(string str, int i, int j)
{
    if ( is_palindrome(str, i, j))
    {
        return 0;
    }
    int res = INT_MAX;
    for (int k = i; k < j; k++)
    {
        res = min(res, palindrome_partitioning_naive(str, i, k) +
                           palindrome_partitioning_naive(str, k + 1, j) + 1);
    }
    return res;
}

int palindrome_partitioning(string str, int n)
{
    int dp[n][n];
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            if (is_palindrome(str, i, j))
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
                }
            }
        }
    }

    return dp[0][n - 1];
}
int main()
{
    string str = "geek";
    int res = palindrome_partitioning_naive(str, 0, str.length() - 1);
    cout << res << " ";
    res = palindrome_partitioning(str, str.length());
    cout << res << " ";
    return 0;
}