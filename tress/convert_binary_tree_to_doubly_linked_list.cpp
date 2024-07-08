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

Node *convert_binary_tree_to_doubly_linked_list(Node *root)
{

    static Node *prev = NULL;

    if (root == NULL)
    {
        return root;
    }

    Node *head = convert_binary_tree_to_doubly_linked_list(root->left);
    
    // first element of DLL
    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }

    prev = root;

    convert_binary_tree_to_doubly_linked_list(root->right);

    return head;
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

    Node *res = convert_binary_tree_to_doubly_linked_list(root);

    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->right;
    }

    return 0;
}