#include <iostream>
#include <set>
using namespace std;

void ceiling_on_left_side_in_an_array_naive(int arr[], int n)
{
    cout << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        int res = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] >= arr[i])
            {
                res = min(res, arr[j]);
            }
        }
        if (res != INT_MAX)
        {
            cout << res << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
}

void ceiling_on_left_side_in_an_array(int arr[], int n)
{
    set<int> s;
    s.insert(arr[0]);
    cout << -1 << " ";

    for (int i = 1; i < n; i++)
    {
        if (s.lower_bound(arr[i]) != s.end())
        {
            cout << *s.lower_bound(arr[i]) << " ";
        }
        else
        {
            cout << -1 << " ";
        }
        s.insert(arr[i]);
    }
}

int main()
{
    int arr[] = {2, 8, 30, 15, 25, 12};
    int n = sizeof(arr) / sizeof(int);

    ceiling_on_left_side_in_an_array_naive(arr, n);
    cout << endl;
    ceiling_on_left_side_in_an_array(arr, n);

    return 0;
}