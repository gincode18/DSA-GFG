#include <iostream>
#include <queue>
using namespace std;

// int rotten_oranges_naive(vector<vector<int>> &arr, int v) {}

int rotten_oranges(vector<vector<int>> arr, int v)
{
    vector<vector<bool>> visited(v, vector<bool>(v, false));
    int total_fresh_oranges = 0;
    int time = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (arr[i][j] == 2 && visited[i][j] == false)
            {
                visited[i][j] = true;
                q.push({i, j});
            }
            if (arr[i][j] == 1)
            {
                total_fresh_oranges++;
            }
        }
    }

    bool changed = false;

    while (q.empty() == false)
    {
        pair<int, int> fornt = q.front();
        int i = fornt.first;
        int j = fornt.second;
        q.pop();

        vector<vector<int>> distances = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

        for (auto dis : distances)
        {
            int new_row = i + dis[0];
            int new_col = j + dis[1];

            if (new_row < v && new_col < v && new_col >= 0 && new_row >= 0)
            {
                if (arr[new_row][new_col] == 1 && visited[new_row][new_col] == false)
                {
                    arr[new_row][new_col] = 2;
                    visited[new_row][new_col] = true;
                    q.push({new_row, new_col});
                    changed = true;
                    total_fresh_oranges--;
                }
            }
        }

        if (changed)
        {
            time++;
        }
    }

    if (total_fresh_oranges != 0)
    {
        return -1;
    }

    else
    {
        return time;
    }
}

int main()
{
    vector<vector<int>> arr = {
        {0, 1, 2},
        {0, 1, 2},
        {2, 1, 1}};

    // int res = rotten_oranges_naive(arr, arr.size());
    // cout << res << " ";

    int res = rotten_oranges(arr, arr.size());
    cout << res << " ";

    return 0;
}
