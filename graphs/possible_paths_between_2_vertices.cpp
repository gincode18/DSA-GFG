#include <iostream>
#include <queue>
using namespace std;

int possible_paths_between_2_vertices(int v, vector<int> arr[], int source, int destination)
{
    queue<int> q;
    q.push(source);
    int res = 0;

    while (q.empty() == false)
    {
        int front = q.front();
        q.pop();

        if (front == destination)
        {
            res++;
        }

        for (auto adj : arr[front])
        {
            q.push(adj);
        }
    }

    return res;
}

int main()
{
    int v = 5;
    int source = 0;
    int destination = 4;

    vector<int> arr[] = {{1, 2, 4}, {3, 4}, {4}, {2}, {}};
    int res = possible_paths_between_2_vertices(v, arr, source, destination);
    cout << res << " ";

    return 0;
}