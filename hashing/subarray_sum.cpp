#include <iostream>
#include <unordered_set>
using namespace std;

int subarray_sum(vector<int> &arr, int n, int sum)
{ // prefixsum2=sum+prefixsum1
    unordered_set<int> set;
    int prefix_sum = 0;
    for (auto num : arr)
    {
        prefix_sum += num;
        if (prefix_sum == sum)
        {
            cout << "true";
            return 1;
        }

        if (set.find(prefix_sum - sum) != set.end())
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
    vector<int> arr = {3, 1, 0, 1, 8, 2, 3, 6};
    int n = arr.size();
    subarray_sum(arr, n, 5);
    return 0;
}