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
int height_of_binary_tree(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    return max(height_of_binary_tree(head->left), height_of_binary_tree(head->right)) + 1;
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
    int res = height_of_binary_tree(root);
    cout<<res<<" ";
    return 0;
}