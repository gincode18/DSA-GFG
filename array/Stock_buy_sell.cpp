#include <iostream>
using namespace std;
int stock_span_naive(int arr[], int start, int end)
{
    if (start >= end)
    {
        return 0;
    }
    int profit = 0;
    for (int i = start; i <= end; i++)
    {
        for (int j = i + 1; j <= end; j++)
            if (arr[i] < arr[j])
            {
                {
                    int curr_profit = arr[j] - arr[i] + stock_span_naive(arr, start, i - 1) + stock_span_naive(arr, j + 1, end);
                    profit = max(profit, curr_profit);
                }
            }
    }
    return profit;
}
int main()
{
    int arr[] = {1, 5, 3, 8, 12};
    cout << stock_span_naive(arr, 0, 4);
    return 0;
}