#include <iostream>
using namespace std;

bool is_valid(int x, int y, int row, int col, vector<vector<bool>> &visited)
{
    if (x >= 0 && x < row && y >= 0 && y < col && visited[x][y] == false)
    {
        return true;
    }
    return false;
}

void dfs(vector<vector<char>> &arr, vector<vector<bool>> &visited, int x, int y)
{
    vector<pair<int, int>> distances = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    visited[x][y] = true;

    for (auto distance : distances)
    {
        int new_x = x + distance.first;
        int new_y = y + distance.second;

        if (is_valid(new_x, new_y, arr.size(), arr[0].size(), visited) && arr[new_x][new_y] == 'X')
        {
            dfs(arr, visited, new_x, new_y);
        }
    }
}
// Function to find the number of 'X' total shapes.
int x_total_shapes(vector<vector<char>> &arr)
{
    int count = 0;
    vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 'X' && visited[i][j] == false)
            {

                dfs(arr, visited, i, j);
                ++count;
            }
        }
    }

    return count;
}

int main()
{
    vector<vector<char>> arr = {{'X', 'O', 'X'}, {'O', 'X', 'O'}, {'X', 'X', 'X'}};
    int res = x_total_shapes(arr);
    
    cout << res << " ";

    return 0;
}