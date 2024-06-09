#include <iostream>
using namespace std;

int union_sorted(vector<int> arr1, vector<int> arr2, int n, int m)
{
    int i, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr1[i - 1] && i > 0)
        {
            i++;
            continue;
        }
        if (arr2[j] == arr2[j - 1] && j > 0)
        {
            j++;
            continue;
        }
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }
        if (arr2[j] < arr1[i])
        {
            cout << arr2[j] << " ";
            j++;
        }
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
    while (i < n)
    {
        if (arr1[i] == arr1[i - 1] && i > 0)
        {
            i++;
            continue;
        }
        cout << arr1[i] << " ";
        i++;
    }
    while (j < m)
    {
        if (arr2[j] == arr2[j - 1] && j > 0)
        {
            j++;
            continue;
        }
        cout << arr2[j] << " ";
        j++;
    }

    return 0;
}

int main()
{
    vector<int> arr1 = {3, 11, 20, 80, 88, 88};
    int n = arr1.size();
    vector<int> arr2 = {3, 10, 20, 30, 40, 80};
    int m = arr2.size();
    union_sorted(arr1, arr2, n, m);
    return 0;
}