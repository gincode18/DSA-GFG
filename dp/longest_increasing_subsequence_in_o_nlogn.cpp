#include <iostream>
using namespace std;
int ceil(vector<int> &tail, int low, int high, int key)
{

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (tail[mid] >= key)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}
int longest_increasing_subsequence_in_o_nlogn(vector<int> &arr, int n)
{
    vector<int> tail(n, -1);
    tail[0] = arr[0];
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > tail[res - 1])
        {
            tail[res] = arr[i];
            res++;
        }
        else
        {
            int index = ceil(tail, 0, res - 1, arr[i]);
            tail[index] = arr[i];
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int res = longest_increasing_subsequence_in_o_nlogn(arr, arr.size());
    cout << res << " ";
    return 0;
}