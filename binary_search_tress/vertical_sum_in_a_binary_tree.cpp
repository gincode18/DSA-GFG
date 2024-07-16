#include <iostream>
#include <unordered_map>
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

unordered_map<int, int> map;

void vertical_sum_in_a_binary_tree(Node *root, int distance)
{
    if (root == NULL)
    {
        return;
    }

    vertical_sum_in_a_binary_tree(root->left, distance - 1);

    map[distance] += root->data;

    vertical_sum_in_a_binary_tree(root->right, distance + 1);
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

    vertical_sum_in_a_binary_tree(root, 0);

    for (auto ele : map)
    {
        cout << ele.first << " " << ele.second << "\n";
    }

    return 0;
}