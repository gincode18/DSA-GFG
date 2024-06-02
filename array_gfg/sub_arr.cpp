#include <iostream>
#include <cmath>
using namespace std;

int naivemaxsubSum(int arr[], int n)
{
    int res = arr[0];

    for (int i = 0; i < n; i++)
    {
        int curr_sum = arr[i];

        for (int j = 1; j < n; j++)
        {
            int index = (i + j) % n;

            curr_sum += arr[index];

            res = max(res, curr_sum);
        }
    }
    return res;
}
int maxsubarr(int arr[], int n)
{
    int max_sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        max_sum = max(max_sum + arr[i], arr[i]);
    }
    return max_sum;
}

int main()
{

    int arr[] = {-3, 8, -2, 4, -5, 6}, n = sizeof(arr) / sizeof(int);

    cout << maxsubarr(arr, n);

    return 0;
}
