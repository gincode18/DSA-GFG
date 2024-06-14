#include <iostream>
#include <unordered_map>
using namespace std;

int freq_of_elements(int arr[], int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        if (map.find(arr[i]) != map.end())
        {
            map[arr[i]] = map[arr[i]] + 1;
        }
        else
        {
            map[arr[i]] = 1;
        }
    }
    for (auto ele : map)
    {
        cout << ele.first << " " << ele.second << "\n";
    }

    return 0;
}

int main()
{
    int arr[] = {10, 20, 30, 20, 20, 30, 40};
    int n = sizeof(arr) / sizeof(int);
    freq_of_elements(arr, n);
    return 0;
}