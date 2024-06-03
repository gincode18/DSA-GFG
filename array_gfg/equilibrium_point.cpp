#include <iostream>
using namespace std;

int equilibrium(int arr[], int n)
{
    int sum = 0;
    int leftsum = 0;

    for (int i = 0; i < n; ++i)
        sum += arr[i];

    for (int i = 0; i < n; ++i)
    {
        sum -= arr[i];

        if (leftsum == sum)
            return i;

        leftsum += arr[i];
    }
    return -1;
}
int main()
{
    int arr[] = {2, 8, 2};
    int n = 3;
    cout << equilibrium(arr, n);

    return 0;
}