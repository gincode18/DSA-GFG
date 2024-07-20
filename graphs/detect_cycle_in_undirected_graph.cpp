#include <iostream>
using namespace std;

void add_edge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

bool dfs(vector<int> arr[], int v, vector<bool> &visited, int &start, int parent)
{
    visited[start] = true;

    for (auto ele : arr[start])
    {
        if (visited[ele] == false)
        {
            if (dfs(arr, v, visited, ele, start) == true)
            {
                return true;
            }
        }

        else
        {
            if (ele != parent)
            {
                return true;
            }
        }
    }

    return false;
}

bool detect_cycle_in_undirected_graph(vector<int> arr[], int v)
{
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (dfs(arr, v, visited, i, -1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    /*    0
         / \
        1---4
        | \ |
        2---3
    */
    int v = 5;
    vector<int> arr[v];

    add_edge(arr, 0, 1);
    add_edge(arr, 0, 4);
    add_edge(arr, 1, 2);
    add_edge(arr, 1, 3);
    add_edge(arr, 1, 4);
    add_edge(arr, 2, 3);
    add_edge(arr, 3, 4);

    bool res = detect_cycle_in_undirected_graph(arr, v);

    if (res)
    {
        cout << "loop found";
    }

    else
    {
        cout << "loop found";
    }

    return 0;
}