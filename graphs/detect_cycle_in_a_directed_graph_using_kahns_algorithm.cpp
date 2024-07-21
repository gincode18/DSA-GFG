#include <iostream>
#include <queue>
using namespace std;

void add_edge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
}

bool detect_cycle_in_a_directed_graph_using_kahns_algorithm(vector<int> arr[], int v)
{
    queue<int> q;
    vector<int> in_degree(v, 0);

    for (int i = 0; i < v; i++)
    {
        for (auto num : arr[i])
        {
            in_degree[num]++;
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;

    while (q.empty() == false)
    {
        int front = q.front();
        q.pop();

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

        count++;
    }

    return count != v;
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

    int res = detect_cycle_in_a_directed_graph_using_kahns_algorithm(arr, v);

    if (res)
    {
        cout << "loop";
    }
    else
    {
        cout << "no_loop";
    }

    return 0;
}