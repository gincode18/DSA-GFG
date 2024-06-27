#include <iostream>
using namespace std;

// res = for all i(0,n-1) res(i)*res(n-i-1)

int count_bst_with_n_keys_naive(int n)
{
    int res = 0;
    if (n == 0)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        res += count_bst_with_n_keys_naive(i) * count_bst_with_n_keys_naive(n - i - 1);
    }

    return res;
}

int count_bst_with_n_keys(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}
int main()
{
    int n = 5;
    int res = count_bst_with_n_keys_naive(n);
    cout << res << " ";
    res = count_bst_with_n_keys(n);
    cout << res << " ";
    return 0;
}