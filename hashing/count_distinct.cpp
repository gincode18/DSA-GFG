#include <iostream>
#include <unordered_set>
using namespace std;

int count_distinct(int arr[], int n)
{
    unordered_set<int> set(arr, arr + n);
    return set.size();
}

int main()
{
    int arr[] = {10, 20, 30, 20, 20, 30, 40};
    int n = sizeof(arr) / sizeof(int);
    int res = count_distinct(arr, n);
    cout << res;
    return 0;
}