#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

void k_largest_elements(int arr[], int n, int k)
{
    // first k elements
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // rest of elements
    for (int i = k; i < n; i++)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    for (int i = 0; i < k; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main()
{
int arr[] = {11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45, 77};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    k_largest_elements(arr, n, k);

    return 0;
}