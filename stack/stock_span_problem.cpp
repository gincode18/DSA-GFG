#include <iostream>
#include <stack>
using namespace std;

void stock_span_problem_naive(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int span = 1;
        for (int j = i - 1; j >= 0 && arr[i] >= arr[j]; j--)
        {
            span++;
        }
        cout << span << " ";
    }
}

void stock_span_problem(int arr[], int n)
{
    stack<int> s;
    s.push(0);
    cout << "\n"
         << 1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }

        s.empty() ? cout << i + 1 << " " : cout << i - s.top() << " ";

        s.push(i);
    }
}
int main()
{
    int arr[] = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    int n = sizeof(arr) / sizeof(int);
    stock_span_problem_naive(arr, n);
    stock_span_problem(arr, n);
    return 0;
}