#include <iostream>
using namespace std;

int sort_arr_of012(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    return 0;
}

int main()
{
    vector<int> arr = {1, 0, 1, 2, 1, 2, 1, 0, 0};
    int n = arr.size();
    sort_arr_of012(arr, n);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}