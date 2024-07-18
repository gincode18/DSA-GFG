#include <iostream>
#include <vector>
using namespace std;

void add_edge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

void print_graph(vector<int> arr[])
{
    for (int i = 0; i < arr->size(); i++)
    {
        cout << i << ":";
        for (auto ele : arr[i])
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}

int main()
{
    int v = 4;
    vector<int> arr[v];
    add_edge(arr, 0, 1);
    add_edge(arr, 0, 2);
    add_edge(arr, 1, 2);
    add_edge(arr, 1, 3);

    print_graph(arr);

    return 0;
}