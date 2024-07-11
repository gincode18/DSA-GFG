#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *bfs_parent_map(Node *root, map<Node *, Node *> &map, int start)
{
    queue<Node *> q;
    q.push(root);
    Node *res;

    while (q.empty() == false)
    {

        Node *front = q.front();
        q.pop();

        if (front->data == start)
        {
            res = front;
        }

        if (front->left != NULL)
        {
            q.push(front->left);
            map[front->left] = front;
        }

        if (front->right != NULL)
        {
            q.push(front->right);
            map[front->right] = front;
        }
    }
    return res;
};

int burn_a_binary_tree_from_a_leaf(Node *root, int start)
{
    map<Node *, Node *> parent;
    map<Node *, bool> visited;
    Node *target = bfs_parent_map(root, parent, start);

    queue<Node *> q;

    q.push(target);
    visited[target] = true;

    int time = 0;

    while (q.empty() == false)
    {
        int count = q.size();
        bool flag = false;

        for (int i = 0; i < count; i++)
        {
            Node *front = q.front();
            q.pop();
            
            if (front->left && !visited[front->left])
            {
                flag = true;
                visited[front->left] = true;
                q.push(front->left);
            }

            if (front->right && !visited[front->right])
            {
                flag = true;
                visited[front->right] = true;
                q.push(front->right);
            }
            if (parent[front] && !visited[parent[front]])
            {
                flag = true;
                visited[parent[front]] = true;
                q.push(parent[front]);
            }
        }
        if (flag)
        {
            time++;
        }
    }

    return time;
}

int main()
{
    /*    1
        /   \
       2     3
      / \     \
     4   5     6
    / \       / \
   7   8     9  10
   */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    int res = burn_a_binary_tree_from_a_leaf(root, 5);
    cout << res << " ";
    return 0;
}