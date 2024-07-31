#include <iostream>
using namespace std;

void rearrange_an_array_with_o_1_extra_space(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] += (arr[arr[i]] % n) * n;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] / n;
    }
}

int main()
{
    int n = 5;
    int arr[] = {4, 0, 2, 1, 3};

    rearrange_an_array_with_o_1_extra_space(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}