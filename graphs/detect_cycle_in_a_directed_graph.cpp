#include <iostream>
using namespace std;

void add_edge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
}

bool dfs(vector<int> arr[], int v, vector<bool> &visited, vector<bool> &rec_stack, int start)
{
    visited[start] = true;
    rec_stack[start] = true;

    for (auto ele : arr[start])
    {
        if (visited[ele] == false)
        {
            if (dfs(arr, v, visited, rec_stack, ele) == true)
            {
                return true;
            }
        }

        else
        {
            if (rec_stack[ele])
            {
                return true;
            }
        }
    }

    rec_stack[start] = false;
    return false;
}

bool detect_cycle_in_a_directed_graph(vector<int> arr[], int v)
{
    vector<bool> visited(v, false);
    vector<bool> rec_stack(v, false);

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            rec_stack[i] = true;
            if (dfs(arr, v, visited, rec_stack, i))
            {
                return true;
            }
        }
    }
    return false;
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

    bool res = detect_cycle_in_a_directed_graph(arr, v);

    if (res)
    {
        cout << "loop found";
    }

    else
    {
        cout << "no loop found";
    }

    return 0;
}