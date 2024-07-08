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

void print_nodes_at_k_distance(Node *head, int k)
{
    if (head == NULL)
    {
        return;
    }
    
    if (k == 0)
    {
        cout << head->data << " ";
    }

    print_nodes_at_k_distance(head->left, k - 1);
    print_nodes_at_k_distance(head->right, k - 1);
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
    print_nodes_at_k_distance(root, 2);
    return 0;
}