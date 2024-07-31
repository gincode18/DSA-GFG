#include <iostream>
using namespace std;

bool check_if_array_is_sorted_and_rotated(int arr[], int n)
{
    int count_asc = 0, count_desc = 0;

    // Check the number of ascending breaks
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            count_asc++;
        }
    }

    // Special case to check the rotation point from end to start for ascending
    if (arr[n - 1] > arr[0])
    {
        count_asc++;
    }

    // Check the number of descending breaks
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] < arr[i])
        {
            count_desc++;
        }
    }

    // Special case to check the rotation point from end to start for descending
    if (arr[n - 1] < arr[0])
    {
        count_desc++;
    }

    // The array is rotated and sorted if and only if there is exactly one break point in ascending or descending order
    return count_asc == 1 || count_desc == 1;
}

int main()
{
    int arr[] = {3, 4, 1, 2};
    int n = 4;
    bool res = check_if_array_is_sorted_and_rotated(arr, n);

    cout << res;

    return 0;
}