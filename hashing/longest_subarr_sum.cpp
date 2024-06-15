#include <iostream>
#include <unordered_map>
using namespace std;

int longest_subarr_sum(vector<int> &arr, int n, int sum)
{ // prefixsum2=sum+prefixsum1
    unordered_map<int, int> map;
    int prefix_sum = 0;
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if (prefix_sum == sum)
        {
            res = max(res, i + 1);
        }

        if (map.find(prefix_sum - sum) != map.end())
        {
            res = max(res, i - map[prefix_sum - sum]);
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
    vector<int> arr = {0, 3, 1, 0, 1, 8, 2, 3, 6};
    int n = arr.size();
    int res = longest_subarr_sum(arr, n, 5);
    cout << res;
    return 0;
}