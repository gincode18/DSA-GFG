#include <iostream>
using namespace std;

int minimum_coins_to_make_a_value_naive(int coins[], int n, int val)
{
    if (val == 0)
    {
        return 0;
    }
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= val)
        {
            int sub_res = 1 + minimum_coins_to_make_a_value_naive(coins, n, val - coins[i]);
            if (sub_res != INT_MAX)
            {
                res = min(res, sub_res);
            }
        }
    }

    return res;
}

int minimum_coins_to_make_a_value(int coins[], int n, int val)
{
    int dp[val + 1];
    dp[0] = 0;
    for (int i = 1; i <= val; i++)
    {
        dp[i] = INT_MAX;
    }
    for (int i = 1; i <= val; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                int sub_res = dp[i - coins[j]] + 1;
                if (sub_res != INT_MAX)
                {
                    dp[i] = min(dp[i], sub_res);
                }
            }
        }
    }
    return dp[val];
}

int main()
{
    int coins[] = {10, 5};
    int val = 30;
    int n = sizeof(coins) / sizeof(int);
    int res = minimum_coins_to_make_a_value_naive(coins, n, val);
    cout << res << " ";
    res = minimum_coins_to_make_a_value(coins, n, val);
    cout << res << " ";
    return 0;
}