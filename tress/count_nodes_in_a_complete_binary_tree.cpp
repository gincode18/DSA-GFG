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

int count_nodes_in_a_complete_binary_tree_naive(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + count_nodes_in_a_complete_binary_tree_naive(root->left) + count_nodes_in_a_complete_binary_tree_naive(root->right);
}

int count_nodes_in_a_complete_binary_tree(Node *root)
{
    int lh = 0, rh = 0;
    Node *curr = root;
    while (curr != NULL)
    {
        lh++;
        curr = curr->left;
    }
    curr = root;
    while (curr != NULL)
    {
        rh++;
        curr = curr->right;
    }
    if (lh == rh)
    {
        return pow(2, lh) - 1;
    }
    else
    {
        return 1 + count_nodes_in_a_complete_binary_tree(root->left) + count_nodes_in_a_complete_binary_tree(root->right);
    }
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
    int res = count_nodes_in_a_complete_binary_tree_naive(root);
    cout << res << " ";
    res = count_nodes_in_a_complete_binary_tree(root);
    cout << res;
    return 0;
}