#include <iostream>
#include <queue>
using namespace std;

void add_edge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
}

void topological_sorting_kahns_bfs_based_algortihm(vector<int> arr[], int v)
{
    vector<int> in_degree(v, 0);
    queue<int> q;

    // collecting all indigree

    for (int i = 0; i < v; i++)
    {
        for (auto ele : arr[i])
        {
            in_degree[ele]++;
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    while (q.empty() == false)
    {
        int front = q.front();
        q.pop();

        cout << front << " ";

        for (auto num : arr[front])
        {
            if (in_degree[num] > 0)
            {
                in_degree[num]--;
                if (in_degree[num] == 0)
                {
                    q.push(num);
                }
            }
        }
    }
}

int main()
{
    /*
        0 → 1
            ↑
        2 → 1
        |
        ↓
        3 → 4 → 5
        ↑      ↓
        └──────┘
    */
    int v = 6;
    vector<int> arr[v];

    add_edge(arr, 0, 1);
    add_edge(arr, 2, 1);
    add_edge(arr, 2, 3);
    add_edge(arr, 3, 4);
    add_edge(arr, 4, 5);
    add_edge(arr, 5, 3);

    topological_sorting_kahns_bfs_based_algortihm(arr, v);

    return 0;
}