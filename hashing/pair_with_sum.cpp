#include <iostream>
#include <unordered_set>
using namespace std;

int pair_with_sum(vector<int> &arr, int n, int sum)
{
    unordered_set<int> set;
    for (auto num : arr)
    {
        if (set.find(sum - num) != set.end())
        {
            cout << "true";
            return 1;
        }
        else
        {
            set.insert(num);
        }
    }
    cout << "false";
    return 0;
}

int main()
{
    vector<int> arr = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    int n = arr.size();
    pair_with_sum(arr, n, 6);
    return 0;
}