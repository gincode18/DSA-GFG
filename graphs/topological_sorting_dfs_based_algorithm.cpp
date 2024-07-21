#include <iostream>
#include <stack>
using namespace std;

void add_edge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
}

void DFS(vector<int> arr[], int v, vector<bool> &visited, int start, stack<int> &st)
{
    visited[start] = true;

    for (auto ele : arr[start])
    {
        if (visited[ele] == false)
        {
            DFS(arr, v, visited, ele, st);
        }
    }

    st.push(start);
}

void topological_sorting_dfs_based_algorithm(vector<int> arr[], int v)
{
    stack<int> st;
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            DFS(arr, v, visited, i, st);
        }
    }
    while (st.empty() == false)
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    /*
        0 → 1
            ↓
            3
         ↗  ↓
        2 ← 4

    */

    int v = 5;
    vector<int> arr[v];

    add_edge(arr, 0, 1);
    add_edge(arr, 1, 3);
    add_edge(arr, 2, 3);
    add_edge(arr, 3, 4);
    add_edge(arr, 2, 4);

    topological_sorting_dfs_based_algorithm(arr, v);
    return 0;
}