#include <iostream>
#include <stack>

using namespace std;

int largest_rectangular_area_in_a_histogram(int arr[], int n)
{
    stack<int> s;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            int top = s.top();
            s.pop();
            curr = arr[top] * (s.empty() ? i : i - s.top() - 1);
            res = max(curr, res);
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int curr = 0;
        int top = s.top();
        s.pop();
        curr = arr[top] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }
    return res;
}

int largest_rectangle_with_all_1_s(int arr[][4], int r, int c)
{
    int res = largest_rectangular_area_in_a_histogram(arr[0], c);
    for (int i = 1; i < r; i++)
    { // processing matrix
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 1)
            {
                arr[i][j] += arr[i - 1][j];
            }
        }
        //calculating max area
        res = max(res, largest_rectangular_area_in_a_histogram(arr[i], c));
    }
    return res;
}

int main()
{
    int arr[4][4] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
    };
    int res = largest_rectangle_with_all_1_s(arr, 4, 4);
    cout << res << " ";

    return 0;
}