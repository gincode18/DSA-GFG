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

Node *bst_deletion(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key > root->data)
    {
        root->right = bst_deletion(root->right, key);
    }

    if (key < root->data)
    {
        root->left = bst_deletion(root->left, key);
    }

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        else
        {
            Node *succ = get_successor(root);
            root->data = succ->data;
            root->right = bst_deletion(root->right, succ->data);
        }

        return root;
    }

    return root;
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

    Node *res = bst_deletion(root, 3);
    cout << res->data << "\n";
    inorder(root);
    return 0;
}