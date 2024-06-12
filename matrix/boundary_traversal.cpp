#include <iostream>
using namespace std;

int boundary_traversal(vector<vector<int>> &arr, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        cout << arr[0][i] << " ";
    }
    for (int i = 1; i < n - 1; i++)
    {
        cout << arr[i][m - 1] << " ";
    }
    if (n > 1)
    {
        for (int i = m - 1; i >= 1; i--)
        {
            cout << arr[n - 1][i] << " ";
        }
    }
    if (m > 1)
    {
        for (int i = n - 1; i >= 1; i--)
        {
            cout << arr[i][0] << " ";
        }
    }

    return 0;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    int n = arr.size();
    int m = arr[0].size();
    boundary_traversal(arr, n, m);
    return 0;
}