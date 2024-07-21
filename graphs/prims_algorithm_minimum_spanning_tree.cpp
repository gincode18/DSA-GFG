#include <iostream>
using namespace std;

int prims_algorithm_minimum_spanning_tree(vector<vector<int>> arr, int v)
{
    vector<int> distance(v, INT_MAX);
    vector<bool> visited(v, false);

    distance[0] = 0;
    int res = 0;

    // find minimum
    for (int count = 0; count < v; count++)
    {
        int u = -1;
        for (int i = 0; i < v; i++)
        {
            if (visited[i] == false && (u == -1 || distance[i] < distance[u]))
            {
                u = i;
            }
        }
        // using minimum path
        visited[u] = true;
        res = res + distance[u];
        // update the distance array
        for (int i = 0; i < v; i++)
        {
            if (arr[u][i] != 0 && visited[i] == false)
            {
                distance[i] = min(distance[i], arr[u][i]);
            }
        }
    }

    return res;
}

int main()
{

    vector<vector<int>> arr = {
        {0, 5, 8, 0},
        {5, 0, 10, 15},
        {8, 10, 0, 20},
        {0, 15, 20, 0},
    };

    cout << prims_algorithm_minimum_spanning_tree(arr, arr.size());
    return 0;
}
