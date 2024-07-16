#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int lcount;

    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
        this->lcount = 0;
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
        root->lcount++;
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}

int counter = 0;

Node *find_kth_smallest_in_bst_naive(Node *root, int &k)
{
    if (root == NULL)
    {
        return root;
    }

    Node *left = find_kth_smallest_in_bst_naive(root->left, k);

    if (left != NULL)
    {
        return left;
    }

    counter++;
    if (k == counter)
    {
        return root;
    }

    return find_kth_smallest_in_bst_naive(root->right, k);
}

Node *find_kth_smallest_in_bst(Node *root, int k)
{
    if (root == NULL)
    {
        return root;
    }

    int counter = root->lcount + 1;

    if (k == counter)
    {
        return root;
    }

    if (counter > k)
    {
        return find_kth_smallest_in_bst(root->left, k);
    }
    // if u move to right root there all the nodes in left tree are samller than right BST
    return find_kth_smallest_in_bst(root->right, k - counter);
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
    int k = 3;

    Node *res = find_kth_smallest_in_bst_naive(root, k);
    cout << res->data << " ";

    res = find_kth_smallest_in_bst(root, k);
    cout << res->data << " ";
    return 0;
}