#include <iostream>
#include <cmath>
using namespace std;

int maxCircularSum(int arr[], int n)
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

int main()
{

    int arr[] = {5, -2, 3, 4}, n = 4;

    cout << maxCircularSum(arr, n);

    return 0;
}
