#include <iostream>
#include <unordered_set>
using namespace std;

int intersection_of_unsorted(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    unordered_set<int> set(arr2.begin(), arr2.end());
    for (auto num : arr1)
    {
        if (set.find(num) != set.end())
        {
            cout << num << " ";
        }
    }

    return 0;
}

int main()
{
    vector<int> arr1 = {10, 20, 30};
    vector<int> arr2 = {10, 30, 40};
    intersection_of_unsorted(arr1, arr2, arr1.size(), arr2.size());
    return 0;
}