#include <iostream>
#include <unordered_set>

using namespace std;

int subarr_sum_0(vector<int> &arr, int n)
{
    unordered_set<int> set;
    int prefix_sum = 0;
    for (auto num : arr)
    {
        prefix_sum += num;
        if (set.find(prefix_sum) != set.end())
        {
            cout << "true";
            return 1;
        }
        else
        {
            set.insert(prefix_sum);
        }
    }
    cout << "false";
    return 0;
}

int main()
{
    vector<int> arr = {-3, 8, -2, 7, -5, 6};
    int n = arr.size();
    subarr_sum_0(arr, n);
    return 0;
}