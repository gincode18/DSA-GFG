#include <iostream>
#include <unordered_set>
using namespace std;

int longest_consecutive_subsequence(vector<int> &arr, int n)
{
    unordered_set<int> set;
    for (auto num : arr)
    {
        set.insert(num);
    }
    int res = 1;

    for (auto num : set)
    {
        int count = 1;
        if (set.find(num - 1) != set.end())
        {
            continue;
        }
        else
        {
            while (set.find(num + 1) != set.end())
            {
                count++;
                res = max(res, count);
                num = num + 1;
            }
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 3, 2, 4, 9, 7, 5};
    int res = longest_consecutive_subsequence(arr, arr.size());
    cout << res;
    return 0;
}
