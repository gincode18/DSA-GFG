#include <iostream>
#include <deque>

using namespace std;

void maximums_of_all_subarrays_of_size_k(int arr[], int n, int k)
{
    deque<int> dq;
    // first k element
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.front()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k; i < n; i++)
    {
        cout << arr[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[dq.front()] <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << arr[dq.front()] << " ";
}

int main()
{
    int arr[] = {10, 8, 5, 12, 15, 7, 6};
    int k = 3;
    int n = sizeof(arr) / sizeof(int);
    maximums_of_all_subarrays_of_size_k(arr, n, k);
    return 0;
}