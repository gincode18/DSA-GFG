#include <iostream>
using namespace std;

int meeting_max_guest(vector<int> &arr, vector<int> &dep, int n)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 1, j = 0, count = 1, res = 1;
    while (j < n && i < n)
    {
        if (arr[i] <= dep[j])
        {
            i++;
            count++;
        }
        else
        {
            count--;
            j++;
        }
        res = max(res, count);
    }

    return res;
}

int main()
{
    vector<int> arr = {900, 600, 700};
    vector<int> dep = {700, 800, 730};
    int n = arr.size();
    int x = meeting_max_guest(arr, dep, n);
    cout << x;
    return 0;
}