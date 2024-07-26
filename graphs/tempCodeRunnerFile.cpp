#include <iostream>
#include <queue>
using namespace std;

class cell
{
public:
    int x, y, dist;
    cell(int x, int y, int dist);
};

cell::cell(int x, int y, int dist)
{
    this->x = x;
    this->y = y;
    this->dist = dist;
}

bool is_valid(int x, int y, int n)
{
    if (x >= 1 && x <= n && y >= 1 && y <= n)
    {
        return true;
    }
    return false;
}

int steps_by_knight(pair<int, int> knight_pos, pair<int, int> target_pos, int n)
{
    vector<pair<int, int>> distances = {{-2, -1}, {-2, 1}, {2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, -2}, {-1, 2}};
    queue<cell> q;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

    q.push(cell(knight_pos.first, knight_pos.second, 0));
    visited[knight_pos.first][knight_pos.second] = true;

    while (q.empty() == false)
    {
        cell front = q.front();
        q.pop();

        int knight_x = front.x;
        int knight_y = front.y;

        if (target_pos.first == knight_pos.first && target_pos.second == knight_pos.second)
        {
            return front.dist;
        }

        for (auto distance : distances)
        {
            int new_x = knight_x + distance.first;
            int new_y = knight_y + distance.second;

            if (is_valid(new_x, new_y, n) && visited[new_x][new_y] == false)
            {
                q.push(cell(new_x, new_y, front.dist + 1));
                visited[new_x][new_y] = true;
            }
        }
    }
    return -1;
}

int main()
{
    pair<int, int> knight_pos = {4, 5};
    pair<int, int> target_pos = {1, 1};

    int n = 6;
    int res = steps_by_knight(knight_pos, target_pos, n);
    cout << res << " ";

    return 0;
}
