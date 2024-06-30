#include <iostream>
#include <stack>
using namespace std;

void previous_greater_element_naive(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int res = -1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
            {
                res = arr[j];
                break;
            }
        }
        cout << res << " ";
    }
}

void previous_greater_element(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout << "\n"
         << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }

        s.empty() ? cout << -1 << " " : cout << s.top() << " ";
        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    int n = sizeof(arr) / sizeof(int);
    previous_greater_element_naive(arr, n);
    previous_greater_element(arr, n);
    return 0;
}