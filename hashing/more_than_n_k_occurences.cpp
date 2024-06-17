#include <iostream>
#include <unordered_map>
using namespace std;

int more_than_n_k_occurences(vector<int> &arr, int n, int k)
{
    unordered_map<int, int> map;
    for (auto num : arr)
    {
        map[num] += 1;
    }
    for (auto num : map)
    {
        if (num.second > n / k)
        {
            cout << num.first << " ";
        }
    }

    return 0;
}

int main()
{
    vector<int> arr = {10, 20, 20, 10, 40, 30, 10};
    more_than_n_k_occurences(arr, arr.size(), 4);
    return 0;
}