#include <iostream>
#include <unordered_map>
using namespace std;

int longest_subarr_with_equal0_1(vector<int> &arr, int n)
{
    unordered_map<int, int> map;
    int prefix_sum = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] == 1 ? prefix_sum++ : prefix_sum--;
        if (prefix_sum == 0)
        {
            res = max(res, i + 1);
        }
        if (map.find(prefix_sum) != map.end())
        {
            res = max(res, i - map[prefix_sum]);
        }
        else
        {
            map[prefix_sum] = i;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 0, 1, 1, 1, 0, 0};
    int n = arr.size();
    int res = longest_subarr_with_equal0_1(arr, n);
    cout << res;
    return 0;
}