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
int main()
{
    int arr[] = {10, 10, 10, 20, 20, 30, 30};
    int n = sizeof(arr) / sizeof(int);
    int x = removeDup(arr, n);
    for (int i = 0; i < x; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}