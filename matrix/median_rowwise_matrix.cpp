#include <iostream>
using namespace std;

int median_rowwise_matrix(vector<vector<int>> &arr, int n, int m)
{
    int min = arr[0][0], max = arr[0][m - 1];
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] < min)
        {
            min = arr[i][0];
        }
        if (arr[i][m - 1] > max)
        {
            max = arr[i][m - 1];
        }
    }
    int mid_index = (m * n + 1) / 2;
    while (min < max)
    {
        int mid = (min + max) / 2;
        int mid_pos = 0;
        for (int i = 0; i < n; i++)
        {
            mid_pos = mid_pos + (upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin());
        }
        if (mid_pos < mid_index)
        {
            min = mid + 1;
        }
        else
        {
            max = mid;
        }
    }

    return min;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int n = arr.size();
    int m = arr[0].size();
    int res = median_rowwise_matrix(arr, n, m);
    cout << res;
    return 0;
}