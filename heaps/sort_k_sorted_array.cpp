#include <iostream>
#include <queue>
using namespace std;

void sort_k_sorted_array(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    // first k elements
    for (int i = 0; i <= k; i++)
    {
        pq.push(arr[i]);
    }
    // index
    int index = 0;
    // rest of elements
    for (int i = k + 1; i < n; i++)
    {
        int top = pq.top();
        pq.pop();
        arr[index++] = top;
        pq.push(arr[i]);
    }
    // remaining elements
    while (pq.empty() == false)
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}

int main()
{
    int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort_k_sorted_array(arr, n, k);
    for (auto ele : arr)
    {
        cout << ele << " ";
    }

    return 0;
}