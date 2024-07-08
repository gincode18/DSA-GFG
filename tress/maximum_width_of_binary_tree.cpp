#include <iostream>
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

int maximum_width_of_binary_tree(Node *root)
{
    if (root == nullptr)
        return 0;

    queue<Node *> q;
    q.push(root);
    int maxWidth = 0;

    while (!q.empty())
    {
        int count = q.size();
        maxWidth = max(maxWidth, count);

        for (int i = 0; i < count; i++)
        {
            Node *node = q.front();
            q.pop();

            if (node->left != nullptr)
            {
                q.push(node->left);
            }

            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
    }

    return maxWidth;
}

int main()
{
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
    int res = maximum_width_of_binary_tree(root);
    cout << res;
    return 0;
}