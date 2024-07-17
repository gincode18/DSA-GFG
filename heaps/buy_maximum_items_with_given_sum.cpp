#include <iostream>
#include <queue>
using namespace std;

int buy_maximum_items_with_given_sum_naive(int arr[], int n, int sum)
{
    sort(arr, arr + n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum - arr[i] >= 0)
        {
            sum = sum - arr[i];
            res++;
        }
        else
        {
            break;
        }
    }

    return res;
}

int buy_maximum_items_with_given_sum(int arr[], int n, int sum)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum - arr[i] >= 0)
        {
            sum = sum - pq.top();
            res++;
        }
        else
        {
            break;
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 12, 5, 111, 200};
    int n = sizeof(arr) / sizeof(int);
    int sum = 10;

    int res = buy_maximum_items_with_given_sum_naive(arr, n, sum);
    cout << res << " ";

    res = buy_maximum_items_with_given_sum(arr, n, sum);
    cout << res << " ";

    return 0;
}