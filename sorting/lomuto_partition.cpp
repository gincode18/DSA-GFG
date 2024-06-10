#include <iostream>
using namespace std;

int lomuto_partition(vector<int> &arr, int l, int h)
{
    int partition = arr[h];
    int i = l - 1;
    for (int j = 0; j < h; j++)
    {
        if (arr[j] < partition)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

int main()
{
    vector<int> arr = {3, 11, 20, 80, 88, 88,1};
    int n = arr.size();
    int x = lomuto_partition(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}