#include <iostream>
#include <stack>
using namespace std;
void next_greater_element_naive(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int res = -1;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] >= arr[i])
            {
                res = arr[j];
            }
        }
        cout << res << " ";
    }
}

void next_greater_element(int arr[], int n)
{
    stack<int> s;
    vector<int> v;
    s.push(arr[n - 1]);
    v.push_back(-1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }

        s.empty() ? v.push_back(-1) : v.push_back(s.top());
        s.push(arr[i]);
    }
    
    reverse(v.begin(), v.end());
    cout << "\n";
    for (auto ele : v)
    {
        cout << ele << " ";
    }
}

int main()
{
    int arr[] = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    int n = sizeof(arr) / sizeof(int);
    next_greater_element_naive(arr, n);
    next_greater_element(arr, n);
    return 0;
}