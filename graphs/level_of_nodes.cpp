#include <iostream>
#include <queue>
using namespace std;

int level_of_nodes(int v, vector<int> arr[], int key)
{
    queue<int> q;
    vector<bool> visited(v, false);

    q.push(0);
    visited[0] = true;
    int level = 0;

    while (q.empty() == false)
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int front = q.front();
            if (front == key)
            {
                return level;
            }

            q.pop();

            for (auto adj : arr[front])
            {
                if (visited[adj] == false)
                {
                    visited[adj] = true;
                    q.push(adj);
                }
            }
        }

        level++;
    }
    return -1;
}

int main()
{
    vector<int> arr[] = {{1, 2}, {0, 3, 4}, {0, 5}, {1}, {1}, {1}};
    int v = 6;
    int key = 4;
    // exprected output : 2

    int res = level_of_nodes(v, arr, key);
    cout << res << " ";
    return 0;
}