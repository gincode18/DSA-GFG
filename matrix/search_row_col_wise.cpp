#include <iostream>
using namespace std;

int search_row_col_wise(vector<vector<int>> &arr, int n, int m, int k)
{
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (arr[i][j] == k)
        {
            cout << "(" << i << " " << j << ")";
            return 0;
        }
        else if (arr[i][j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    cout << "not found";
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
    int k = 16;
    search_row_col_wise(arr, n, m, k);
    return 0;
}