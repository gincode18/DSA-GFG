#include <iostream>
using namespace std;

int bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }

    return 0;
}

int main()
{
    int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    int n = sizeof(arr) / sizeof(int);
    bubble_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}