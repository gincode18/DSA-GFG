#include <iostream>
using namespace std;

bool is_safe(vector<vector<int>> &arr, int x, int y, vector<vector<bool>> &visited)
{
    if (x >= 0 && x < visited.size() && y >= 0 && y < visited[0].size() && visited[x][y] == false && arr[x][y] > 0)
    {
        return true;
    }
    return false;
}

bool dfs_is_path(vector<vector<int>> &arr, int row, int col, vector<vector<bool>> visited)
{
    if (arr[row][col] == 2)
    {
        return true;
    }
    visited[row][col] = true;

    vector<pair<int, int>> distances = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (auto distance : distances)
    {
        int new_row = row + distance.first;
        int new_col = col + distance.second;

        if (is_safe(arr, new_row, new_col, visited))
        {
            dfs_is_path(arr, new_row, new_col, visited);
        }
    }
    return false;
}

bool find_whether_path_exist(vector<vector<int>> &arr)
{

    vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 1 && visited[i][j] == false)
            {
                if (dfs_is_path(arr, i, j, visited))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> arr = {{3, 0, 3, 0, 0},
                               {3, 0, 0, 0, 3},
                               {3, 3, 3, 3, 3},
                               {0, 2, 3, 0, 0},
                               {3, 0, 0, 1, 3}};

    bool res = find_whether_path_exist(arr);
    cout << res << " ";
    return 0;
}