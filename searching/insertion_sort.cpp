#include <iostream>
using namespace std;

int insertion_sort(vector<int> &arr, int n)
{
    for (int i = 1; i < n ; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    return 0;
}

int main()
{
    vector<int> arr = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    int n = arr.size();
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}