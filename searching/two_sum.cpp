#include <iostream>
using namespace std;
bool isPair(int arr[], int n, int x)
{
    int i = 0, j = n - 1;
    while (i < j)
    {

        if (arr[i] + arr[j] == x)
            return true;
        else if (arr[i] + arr[j] < x)
            i++;
        else
            j--;
    }   

    return false;
}

int main()
{

    int arr[] = {5, 20, 40, 30, 20, 50, 60}, n = 7;
    int x = 70;

    cout << isPair(arr, n, x);

    return 0;
}