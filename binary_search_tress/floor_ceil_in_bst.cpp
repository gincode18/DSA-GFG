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

Node *get_successor(Node *target)
{
    target = target->right;

    while (target != NULL && target->left != NULL)
    {
        target = target->left;
    }

    return target;
}

Node *res = NULL;

Node *floor_in_bst(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data > key)
    {
        root = floor_in_bst(root->left, key);
    }

    else
    {
        res = root;
        root = floor_in_bst(root->right, key);
    }

    return res;
}

Node *ceil_in_bst(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data < key)
    {
        root = ceil_in_bst(root->right, key);
    }

    else
    {
        res = root;
        root = ceil_in_bst(root->left, key);
    }

    return res;
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

    Node *res = floor_in_bst(root, 15);
    cout << res->data << " ";

    Node *res1 = ceil_in_bst(root, 2);
    cout << res1->data;
    return 0;
}