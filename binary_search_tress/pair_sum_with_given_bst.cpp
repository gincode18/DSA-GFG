#include <iostream>
#include <unordered_set>
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

unordered_set<int> s;

bool pair_sum_with_given_bst(Node *root, int sum)
{
    if (root == NULL)
    {
        return false;
    }

    if (pair_sum_with_given_bst(root->left, sum))
    {
        return true;
    }

    if (s.find(sum - root->data) != s.end())
    {
        return true;
    }
    s.insert(root->data);

    return pair_sum_with_given_bst(root->right, sum);
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

    cout << pair_sum_with_given_bst(root, 24);

    return 0;
}