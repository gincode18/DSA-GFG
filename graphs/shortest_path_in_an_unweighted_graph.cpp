#include <iostream>
#include <queue>
using namespace std;

void add_edge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

vector<int> shortest_path_in_an_unweighted_graph(vector<int> arr[], int s, int v)
{
    queue<int> q;
    bool visited[v];
    vector<int> dist(v, INT_MAX);

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    q.push(s);
    visited[s] = true;
    dist[s] = 0;

    while (q.empty() == false)
    {
        int front = q.front();
        q.pop();

        for (auto ele : arr[front])
        {
            if (visited[ele] == false)
            {
                visited[ele] = true;
                q.push(ele);
                dist[ele] = dist[front] + 1;
            }
        }
    }

    return dist;
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

    vector<int> res = shortest_path_in_an_unweighted_graph(arr, 0, v);
    for (auto ele : res)
    {
        cout << ele << " ";
    }

    return 0;
}