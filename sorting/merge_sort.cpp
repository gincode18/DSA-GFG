#include <iostream>
using namespace std;
void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> v1(n1);
    vector<int> v2(n2);

    for (int i = 0; i < n1; i++)
    {
        v1[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        v2[i] = arr[m + i + 1];
    }
    int i = 0, j = 0;
    int count = l;
    while (j < n2 && i < n1)
    {
        if (v1[i] <= v2[j])
        {
            arr[count] = v1[i];
            i++;
        }
        else
        {
            arr[count] = v2[j];
            j++;
        }
        count++;
    }
    while (i < n1)
    {
        arr[count] = v1[i];
        i++;
        count++;
    }
    while (j < n2)
    {
        arr[count] = v2[j];
        j++;
        count++;
    }
}
void merge_sort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    vector<int> arr = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    int n = arr.size();
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}