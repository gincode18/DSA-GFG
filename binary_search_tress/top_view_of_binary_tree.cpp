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

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}

map<int, int> mp;

void top_view_of_binary_tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (q.empty() == false)
    {
        pair<Node *, int> front = q.front();
        q.pop();

        if (mp.find(front.second) == mp.end())
        {
            mp[front.second] = front.first->data;
        }

        if (front.first->left != NULL)
        {
            q.push({front.first->left, front.second - 1});
        }

        if (front.first->right != NULL)
        {
            q.push({front.first->right, front.second + 1});
        }
    }
}

int main()
{
    /*    8
        /   \
       3     10
      / \      \
     1   6      14
        / \     /
       4   7   13 */

    Node *root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);

    top_view_of_binary_tree(root);

    for (auto ele : mp)
    {
        cout << ele.second << " ";   
    }

    return 0;
}