#include <iostream>
using namespace std;

int spiral_traversal_matrix(vector<vector<int>> &arr, int n, int m)
{
    int top = 0, right = m - 1, left = 0, bottom = n - 1;
    while (top <= bottom && left <= right)
    {
        // top
        if (top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                cout << arr[top][i] << ' ';
            }
            top++;
        }
        // right
        if (left <= right)
        {
            for (int i = top; i <= bottom; i++)
            {
                cout << arr[i][right] << " ";
            }
            right--;
        }
        // bottom
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << arr[bottom][i] << ' ';
            }
            bottom--;
        }
        // left
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }
            left++;
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
    spiral_traversal_matrix(arr, n, m);
    return 0;
}