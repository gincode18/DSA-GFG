#include <iostream>
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

bool children_sum_property(Node *root)
{
    bool res = false;

    if (root == NULL)
    {
        return true;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    if (root->left == NULL)
    {
        res = root->right->data == root->data;
    }

    else if (root->right == NULL)
    {
        res = root->left->data == root->data;
    }

    else
    {
        res = root->left->data + root->right->data == root->data;
    }

    return res && children_sum_property(root->left) && children_sum_property(root->right);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(1);
    bool res = children_sum_property(root);
    cout << res;
    return 0;
}