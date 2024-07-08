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

int maximum_in_binary_tree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(root->data, max(maximum_in_binary_tree(root->left), maximum_in_binary_tree(root->right)));
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

    int res = maximum_in_binary_tree(root);
    cout << res;
    return 0;
}