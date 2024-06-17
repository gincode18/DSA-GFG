#include <iostream>
#include <unordered_map>
using namespace std;

int count_distinct_elements_in_every_window(vector<int> &arr, int n, int k)
{
    unordered_map<int, int> map;
    for (int i = 0; i < k; i++)
    {
        if (map.find(arr[i]) != map.end())
        {
            map[arr[i]]++;
        }
        else
        {
            map[arr[i]] = 1;
        }
    }
    cout << map.size() << " ";
    for (int i = 1, j = k - 1; i < n - k + 1; i++, j++)
    {
        map[arr[i - 1]]--;
        if (map[arr[i - 1]] == 0)
        {
            map.erase(arr[i - 1]);
        }
        map[arr[j+1]] += 1;
        cout << map.size() << " ";
    }

    return 0;
}

int main()
{
    vector<int> arr = {10, 20, 20, 10, 40, 30, 10};
    count_distinct_elements_in_every_window(arr, arr.size(), 4);
    return 0;
}