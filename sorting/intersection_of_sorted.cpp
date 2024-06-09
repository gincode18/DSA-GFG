#include <iostream>
using namespace std;

int intersection_of_sorted(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int i = 0, j = 0;
    while (j < m && i < n)
    {
        if (i > 0 && arr1[i] == arr1[i - 1])
        {
            i++;
            continue;
        }
        if (j > 0 && arr2[j] == arr2[j - 1])
        {
            j++;
            continue;
        }
        if (arr1[i] > arr2[j])
        {
            j++;
        }
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }

    return 0;
}

int main()
{
    vector<int> arr1 = {3, 11, 20, 80, 88, 88};
    int n = arr1.size();
    vector<int> arr2 = {3, 10, 20, 30, 40, 80};
    int m = arr2.size();
    intersection_of_sorted(arr1, arr2, n, m);
    return 0;
}