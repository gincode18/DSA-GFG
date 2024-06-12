#include <iostream>
using namespace std;
bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int merge_ovelapping_interval(vector<pair<int, int>> &arr, int n)
{
    sort(arr.begin(), arr.end(), compare);
    int res = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[res].second >= arr[i].first)
        {
            arr[res].first = min(arr[res].first, arr[i].first);
            arr[res].second = max(arr[res].second, arr[i].second);
        }
        else
        {
            res++;
            arr[res] = arr[i];
        }
    }

    for (size_t i = 0; i <= res; i++)
    {
        cout << arr[i].first << "," << arr[i].second << "| ";
    }

    return 0;
}

int main()
{
    vector<pair<int, int>> arr = {{3, 4}, {1, 2}, {2, 3}, {3, 1}, {2, 2},{10,11}};
    int n = arr.size();
    merge_ovelapping_interval(arr, n);
    return 0;
}