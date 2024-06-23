#include <iostream>
using namespace std;

int longest_increasing_subsequence(vector<int> &arr, int n)
{
    vector<int> dp(n, 1);
    dp[0] = 1;
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    res = 0;

    for (auto num : dp)
    {
        res = max(res, num);
    }

    return res;
}

int main()
{
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int res = longest_increasing_subsequence(arr, arr.size());
    cout << res << " ";
    return 0;
}