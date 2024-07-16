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

Node *prev_node = NULL, *first_node = NULL, *second_node = NULL;

void fix_bst_with_two_nodes_swapped(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    fix_bst_with_two_nodes_swapped(root->left);

    if (prev_node != NULL && root->data < prev_node->data)
    {
        if (first_node == NULL)
        {
            first_node = prev_node;
            second_node = root;
        }
        else
        {
            second_node = root;
        }
    }

    prev_node = root;

    fix_bst_with_two_nodes_swapped(root->right);
}

int main()
{

    /*       18
            /  \
          60    70
         /     /  \
        4     8    80
     */

    Node *root = new Node(18);
    root->left = new Node(60);
    root->right = new Node(70);
    root->left->left = new Node(4);
    root->right->left = new Node(8);
    root->right->right = new Node(80);

    cout << "before:" << " ";
    inorder(root);
    cout << endl;
    cout << "after:" << " ";
    fix_bst_with_two_nodes_swapped(root);

    int temp = first_node->data;
    first_node->data = second_node->data;
    second_node->data = temp;

    inorder(root);

    return 0;
}