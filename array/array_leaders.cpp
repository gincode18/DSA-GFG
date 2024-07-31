//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int n, int arr[])
    {
        vector<int> res;

        res.push_back(arr[n - 1]);
        int max_val = arr[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {

            if (arr[i] >= max_val)
                res.push_back(arr[i]);
            max_val = max(arr[i], max_val);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;
    cin >> t; // testcases
    while (t--)
    {
        long long n;
        cin >> n; // total size of array

        int arr[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(n, arr);

        // printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout << *it << " ";
        }

        cout << endl;
    }
}

// } Driver Code Ends