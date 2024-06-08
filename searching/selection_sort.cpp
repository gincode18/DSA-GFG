#include <iostream>
using namespace std;

int selection_sort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }

    return 0;
}

int main()
{
    vector<int> arr = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    int n = arr.size();
    selection_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}