#include <iostream>
using namespace std;
int count_merge(vector<int> &arr, int l, int m, int r)
{
    int i = 0, j = 0, k = l, res = 0;
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> left(n1);
    vector<int> right(n2);
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[m + i + 1];
    }

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            // important step
            res = res + (n1 - i);
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

    return res;
}
int count_inversion(vector<int> &arr, int l, int r)
{
    int res = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        res += count_inversion(arr, l, m);
        res += count_inversion(arr, m + 1, r);
        res += count_merge(arr, l, m, r);
    }
    return res;
}

int main()
{
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();
    int x = count_inversion(arr, 0, n - 1);
    cout << x;
    return 0;
}