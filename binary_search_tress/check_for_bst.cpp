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

int prev_node = INT_MIN;

bool check_for_bst(Node *root)
{

    if (root == NULL)
    {
        return true;
    }

    if (check_for_bst(root->left) == false)
    {
        return false;
    }

    if (root->data < prev_node)
    {
        return false;
    }

    prev_node = root->data;

    return check_for_bst(root->right);
}

bool check_for_bst_using_ranges(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    return (root->data > min && root->data < max) &&
           check_for_bst_using_ranges(root->left, min, root->data) &&
           check_for_bst_using_ranges(root->right, root->data, max);
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

    bool res = check_for_bst(root);
    cout << res << " ";

    res = check_for_bst_using_ranges(root, INT_MIN, INT_MAX);
    cout << res << " ";

    return 0;
}