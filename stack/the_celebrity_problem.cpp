#include <iostream>
using namespace std;
bool knows(int arr[][3], int a, int b)
{
    if (arr[a][b] == 1)
    {
        return true;
    }
    return false;
}

int the_celebrity_problem(int arr[][3], int n)
{
    // finding candidate
    int candidate = 0;
    for (int i = 0; i < n; i++)
    {
        if (candidate != i && knows(arr, candidate, i))
        {
            candidate = i;
        }
    }

    // verify candidate
    for (int i = 0; i < n; i++)
    {
        if (candidate != i && (knows(arr, candidate, i) || !knows(arr, i, candidate)))
        {
            return -1;
        }
    }
    return candidate;
}

int main()
{
    int arr[3][3] = {{1, 0, 0},
                     {0, 1, 0},
                     {0, 0, 1}};
    int res = the_celebrity_problem(arr, 3);
    cout << res << " ";
    return 0;
}