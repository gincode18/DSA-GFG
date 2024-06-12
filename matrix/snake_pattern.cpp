#include <iostream>
using namespace std;

int snake_pattern(vector<vector<int>> &arr, int n, int m)
{
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (count % 2 == 0)
        {
            for (size_t j = 0; j < m; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for (int j = m - 1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
        }
        count++;
        cout << "\n";
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
    snake_pattern(arr, n, m);
    return 0;
}