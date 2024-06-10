#include <iostream>
using namespace std;
int partition(vector<int> &arr, int l, int h)
{
    int i = l - 1;
    int pivot = arr[h];
    for (int j = 0; j < h; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);

    return i + 1;
}
int kth_smallest_element(vector<int> arr, int n, int k)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int p = partition(arr, l, h);
        if (p < k - 1)
        {
            l = p + 1;
        }
        else if (p > k - 1)
        {
            h = p - 1;
        }
        if (p == k - 1)
        {
            return arr[p];
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {10, 50, 1, 2, 4, 5};
    int n = arr.size();
    cout << kth_smallest_element(arr, n, 2);
    return 0;
}