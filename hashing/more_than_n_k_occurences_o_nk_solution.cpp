#include <iostream>
#include <unordered_map>
using namespace std;

int more_than_n_k_occurences_o_nk_solution(vector<int> &arr, int n, int k)
{ // using Moore Majority Voting Algorithm
    unordered_map<int, int> map;
    // voting
    for (auto num : arr)
    {
        if (map.find(num) != map.end())
        {
            map[num] += 1;
        }
        else if (map.size() < k - 1)
        {
            map[num] = 1;
        }
        else
        {
            for (auto num : map)
            {
                num.second--;
                if (num.second == 0)
                {
                    map.erase(num.first);
                }
            }
        }
    }
    // verify vote
    for (auto num : map)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == num.first)
            {
                count++;
            }
        }
        if (count > n / k)
        {
            cout << num.first << " ";
        }
    }

    return 0;
}

int main()
{
    vector<int> arr = {30, 10, 20, 20, 20, 10, 40, 30, 30};
    more_than_n_k_occurences_o_nk_solution(arr, arr.size(), 4);
    return 0;
}