#include <iostream>
#include <queue>
using namespace std;

class triplet
{
public:
    int val, apos, vpos;
    triplet(int a, int b, int c)
    {
        this->val = a;
        this->apos = b;
        this->vpos = c;
    }
};

class my_compare
{
public:
    bool operator()(triplet a, triplet b)

    {
        return a.val > b.val;
    }
};

vector<int> merge_k_sorted_arrays_naive(vector<vector<int>> &arr, int k)
{
    vector<int> res;
    priority_queue<triplet, vector<triplet>, my_compare> pq;
    // fill the pq with first k elements
    for (int i = 0; i < k; i++)
    {
        triplet t(arr[i][0], i, 0);
        pq.push(t);
    }

    while (pq.empty() == false)
    {
        triplet top = pq.top();
        int apos = top.apos;
        int vpos = top.vpos;
        pq.pop();
        res.push_back(top.val);

        if (vpos + 1 < arr[apos].size())
        {
            triplet t(arr[apos][vpos + 1], apos, vpos + 1);
            pq.push(t);
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> arr{{10, 20, 30},
                            {5, 15},
                            {1, 9, 11, 18}};

    int k = 3;
    vector<int> res = merge_k_sorted_arrays_naive(arr, k);
    for (auto ele : res)
    {
        cout << ele << " ";
    }

    return 0;
}