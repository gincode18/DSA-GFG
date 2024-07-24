#include <iostream>
#include <queue>
#include <vector>
#include <climits> // for INT_MAX

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
        this->m = b;
        this->n = a;
    }

    void create_graph()
    {
        int k = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If last row, then add edge on right side.
                if (i == n-1)
                {
                    // If not bottom right cell.
                    if (j != m-1)
                    {
                        g[k].push_back(k + 1);
                        g[k + 1].push_back(k);
                    }
                }
                // If last column, then add edge downward.
                else if (j == m-1)
                {
                    g[k].push_back(k + m);
                    g[k + m].push_back(k);
                }
                // Else makes an edge in all four directions.
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
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (int i = 0; i < g[front].size(); i++)
            {
                if (!visited[g[front][i]])
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
    int rows = arr.size();
    int cols = arr[0].size();
    vector<int> distance((rows * cols) + 1, INT_MAX);
    vector<bool> visited((rows * cols) + 1, false);
    queue<int> q;

    Graph g(rows, cols);
    g.create_graph();

    int k = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 1)
            {
                q.push(k);
                distance[k] = 0; // Set the distance to 0 for the cells with 1
                visited[k] = true;
            }
            k++;
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
