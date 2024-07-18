#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;

void k_closest_elements(int arr[], int n, int x, int k)
{
    // first k elements
    for (int i = 0; i < k; i++)
    {
        int diff = abs(x - arr[i]);
        pq.push({diff, arr[i]});
    }

    // rest of elements
    for (int i = k; i < n; i++)
    {
        int diff = abs(x - arr[i]);

        if (pq.top().first > diff)
        {
            pq.pop();
            pq.push({diff, arr[i]});
        }
    }

    for (int i = 0; i < k; i++)
    {
        cout << pq.top().second << " ";
        pq.pop();
    }
}

int main()
{
    int arr[] = {10, 30, 5, 40, 38, 80, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 35;
    int k = 3;

    k_closest_elements(arr, n, x, k);

    return 0;
}