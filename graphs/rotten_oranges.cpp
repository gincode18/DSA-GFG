#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// int rotten_oranges_naive(vector<vector<int>> &arr, int v) {}

int rotten_oranges(vector<vector<int>> arr, int v)
{
    int ct = 0, res = -1;
    // queue to store cells which have rotten oranges.
    queue<vector<int>> q;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // traversing over all the cells of the matrix.
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            // if arr value is more than 0, we increment the counter.
            if (arr[i][j] > 0)
                ct++;
            // if arr value is 2, we push the cell indexes into queue.
            if (arr[i][j] == 2)
                q.push({i, j});
        }
    }
    while (!q.empty())
    {
        // incrementing result counter.
        res++;
        int size = q.size();
        for (int k = 0; k < size; k++)
        {
            // popping the front element of queue and storing cell indexes.
            vector<int> cur = q.front();
            ct--;
            q.pop();

            // traversing the adjacent vertices.
            for (int i = 0; i < 4; i++)
            {
                int x = cur[0] + dir[i][0], y = cur[1] + dir[i][1];

                // if cell indexes are within matrix bounds and arr value
                // is not 1, we continue the loop else we store 2 in current
                // cell and push the cell indexes in the queue.
                if (x >= arr.size() || x < 0 || y >= arr[0].size() || y < 0 ||
                    arr[x][y] != 1)
                    continue;
                arr[x][y] = 2;
                q.push({x, y});
            }
        }
    }
    // returning the minimum time.
    if (ct == 0)
        return max(0, res);
    return -1;
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};

    int res = rotten_oranges(arr, arr.size());
    cout << res << " ";

    return 0;
}
