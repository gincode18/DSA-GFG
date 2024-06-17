#include <iostream>
#include <unordered_map>
using namespace std;

int longest_common_span_with_same_sum_in_binary_arrays(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        int diff = arr1[i] - arr2[i];
        temp.push_back(diff);
    }
    unordered_map<int, int> map;
    int prefix_sum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += temp[i];
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
    vector<int> arr1 = {0, 1, 1, 1, 0, 0, 1};
    int n = arr1.size();
    vector<int> arr2 = {0, 0, 0, 1, 1, 1, 1}; //{0,0,1,1,0,-1,-1} map= 0,0,1,2,2,1,0
    int m = arr2.size();
    int res = longest_common_span_with_same_sum_in_binary_arrays(arr1, arr2, n, m);
    cout << res;
    return 0;
}