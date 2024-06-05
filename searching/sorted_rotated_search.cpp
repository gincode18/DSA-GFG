#include <iostream>
using namespace std;

int sorted_rotated_search(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        // if left is sorted
        if (arr[mid] >= arr[low])
        {
            if (x >= arr[low] && x < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // if right half is sorted
        if (x > arr[mid] && x <= arr[high])
        {
            if (x > arr[mid] && x <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    int arr[] = {20, 30, 40, 50, 10, 1, 2, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << sorted_rotated_search(arr, n, 1);
    return 0;
}