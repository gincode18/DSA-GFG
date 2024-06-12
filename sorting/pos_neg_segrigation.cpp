#include <iostream>
using namespace std;

int pos_neg_segrigation(vector<int> &arr, int n)
{
    int i = -1;
    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] < 0)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    return 0;
}

int main()
{
    vector<int> arr = {10, 20, -10, -9, -8, 50, 90};
    int n = arr.size();
    pos_neg_segrigation(arr, n);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}