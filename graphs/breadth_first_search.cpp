#include <iostream>
#include <queue>
using namespace std;

void add_edge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

void breadth_first_search(vector<int> arr[], int v, int s)
{
    queue<int> q;
    bool visited[v];

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    q.push(s);
    visited[0] = true;

    while (q.empty() == false)
    {
        int front = q.front();
        cout << front << " ";
        q.pop();

        for (auto ele : arr[front])
        {
            if (visited[ele] == false)
            {
                visited[ele] = true;
                q.push(ele);
            }
        }
    }
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

    breadth_first_search(arr, v, 0);

    return 0;
}