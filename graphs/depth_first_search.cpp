#include <iostream>
#include <stack>
using namespace std;

void add_edge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

void depth_first_search_recusrion(vector<int> arr[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";

    for (auto ele : arr[s])
    {
        if (visited[ele] == false)
        {
            depth_first_search_recusrion(arr, ele, visited);
        }
    }
}

void depth_first_search(vector<int> arr[], int s, bool visited[])
{
    stack<int> st;
    st.push(s);
    visited[s] = true;

    while (st.empty() == false)
    {
        int top = st.top();
        st.pop();
        cout << top << " ";

        for (auto ele : arr[top])
        {
            if (visited[ele] == false)
            {
                st.push(ele);
                visited[ele] = true;
                break;
            }
        }
    }
}

int main()
{
    /*    0
         / \
        1---4
        | \ |
        2---3
    */
    int v = 5;
    vector<int> arr[v];

    add_edge(arr, 0, 1);
    add_edge(arr, 0, 4);
    add_edge(arr, 1, 2);
    add_edge(arr, 1, 3);
    add_edge(arr, 1, 4);
    add_edge(arr, 2, 3);
    add_edge(arr, 3, 4);

    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    depth_first_search_recusrion(arr, 0, visited);
   
    cout << endl;

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    
    depth_first_search(arr, 0, visited);

    return 0;
}