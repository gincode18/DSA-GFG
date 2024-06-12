#include <iostream>
using namespace std;

int cycle_sort(vector<int> &arr, int n)
{
    for (size_t cs = 0; cs < n - 1; cs++)
    {
        int item = arr[cs];
        int pos = cs;
        for (size_t i = cs + 1; i < n; i++)
        {
            if (arr[i] < item)
            {
                pos++;
            }
        }
        swap(arr[pos], item);
        while (pos != cs)
        {
            pos = cs;
            for (size_t i = cs + 1; i < n; i++)
            {
                if (arr[i] < item)
                {
                    pos++;
                }
            }
            swap(arr[pos], item);
        }
    }

    return 0;
}

int main()
{
    vector<int> arr = {20, 40, 50, 10, 30, 10, 10, 10, 10};
    int n = arr.size();
    cycle_sort(arr, n);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}