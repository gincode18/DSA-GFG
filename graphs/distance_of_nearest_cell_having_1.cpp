#include <iostream>
#include <queue>
#include <vector>
#define MAX 500
using namespace std;

class Graph
{

public:
    vector<int> g[MAX];
    int n;
    int m;

    Graph(int a, int b)
    {
        this->n = a;
        this->m = b;
        g->resize(a);
    }

    void create_graph()
    {
        int k = 1;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                // If last row, then add edge on right side.
                if (i == n)
                {
                    // If not bottom right cell.
                    if (j != m)
                    {
                        g[k].push_back(k + 1);
                        g[k + 1].push_back(k);
                    }
                }

                // If last column, then add edge toward
                // down.
                else if (j == m)
                {
                    g[k].push_back(k + m);
                    g[k + m].push_back(k);
                }

                // Else makes an edge in all four
                // directions.
                else
                {
                    g[k].push_back(k + 1);
                    g[k + 1].push_back(k);
                    g[k].push_back(k + m);
                    g[k + m].push_back(k);
                }

                k++;
            }
        }
    }

    void bfs(vector<bool> &visited, vector<int> &distance, queue<int> &q)
    {
        while (q.empty() == false)
        {
            int front = q.front();
            q.pop();
            for (int i = 0; i < g[front].size(); i++)
            {

                if (visited[g[front][i]] == false)
                {
                    distance[g[front][i]] = min(distance[g[front][i]], distance[front] + 1);
                    q.push(g[front][i]);
                    visited[g[front][i]] = true;
                }
            }
        }
    }

    void print(vector<int> &distance)
    {
        int count = 0;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                count++;
                cout << distance[count] << " ";
            }
            cout << "\n";
        }
    }
};

void distance_of_nearest_cell_having_1(vector<vector<int>> arr)
{
    vector<int> distance(arr.size() * arr[0].size(), INT_MAX);
    vector<bool> visited(arr.size() * arr[0].size(), 0);
    queue<int> q;

    Graph g(arr.size(), arr[0].size());
    g.create_graph();

    int k = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 1)
            {
                q.push(k);
                k++;
            }
        }
    }
    g.bfs(visited, distance, q);
    g.print(distance);
}

int main()
{
    vector<vector<int>> arr = {{0, 0, 0, 1}, {0, 0, 1, 1}, {0, 1, 1, 0}};
    distance_of_nearest_cell_having_1(arr);
    return 0;
}
