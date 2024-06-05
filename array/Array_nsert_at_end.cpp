#include <iostream>
using namespace std;
void insertAtEnd(int arr[], int sizeOfArray, int element)
{
    sizeOfArray--;
    arr[sizeOfArray] = element;
}
void insertAtIndex(int arr[], int sizeOfArray, int index, int element)
{

    int temp = arr[index];
    arr[index] = element;

    for (int i = index + 1; i < sizeOfArray; i++)
    {
        int x = arr[i];
        arr[i] = temp;
        temp = x;
    }
}
int removeDup(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[res] != arr[i])
        {
            res++;
            arr[res] = arr[i];
        }
    }
    return res + 1;
}
int maxIndexDiff(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
            {
                res = max(res, j - i);
            }
        }
    }
    return res;
}
int main()
{
    int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    int n = sizeof(arr) / sizeof(int);
    cout << maxIndexDiff(arr, n);
    return 0;
}