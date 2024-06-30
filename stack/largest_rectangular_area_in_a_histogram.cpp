#include <iostream>
#include <stack>
using namespace std;

int largest_rectangular_area_in_a_histogram_naive(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int count = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
            {
                count += arr[i];
            }
            else
            {
                break;
            }
        }

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
            {
                count += arr[i];
            }
            else
            {
                break;
            }
        }
        res = max(res, count);
    }
    return res;
}

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

int main()
{
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    int res = largest_rectangular_area_in_a_histogram_naive(arr, n);
    cout << res << " ";
    res = largest_rectangular_area_in_a_histogram(arr, n);
    cout << res << " ";
    return 0;
}