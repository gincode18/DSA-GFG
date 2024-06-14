#include <iostream>
#include <unordered_set>
using namespace std;

int union_of_unsorted(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    unordered_set<int> set(arr1.begin(), arr1.end());
    for (auto num : arr2)
    {
        if (set.find(num) == set.end())
        {
            set.insert(num);
        }
    }

    for (auto num : set)
    {
        cout << num << " ";
    }

    return 0;
}

int main()
{
    vector<int> arr1 = {10, 20, 30};
    vector<int> arr2 = {10, 30, 40};
    union_of_unsorted(arr1, arr2, arr1.size(), arr2.size());
    return 0;
}