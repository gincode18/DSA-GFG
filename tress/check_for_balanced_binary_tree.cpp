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

int height_of_binary_tree(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    return max(height_of_binary_tree(head->left), height_of_binary_tree(head->right)) + 1;
}

bool check_for_balanced_binary_tree_naive(Node *root)
{
    int left_height = 0, right_height = 0, diff = 0;

    left_height = height_of_binary_tree(root->left);

    right_height = height_of_binary_tree(root->right);

    diff = abs(left_height - right_height);
    bool res = diff <= 1;

    return res && height_of_binary_tree(root->left) && height_of_binary_tree(root->right);
}

int check_for_balanced_binary_tree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left_height = 0, right_height = 0, diff = 0;

    left_height = check_for_balanced_binary_tree(root->left);
    right_height = check_for_balanced_binary_tree(root->right);

    if (left_height == -1 || right_height == -1)
    {
        return -1;
    }

    diff = abs(left_height - right_height);

    int res = diff > 1 ? -1 : max(left_height, right_height) + 1;
    return res;
}

int main()
{
    Node *root = new Node(18);
    root->left = new Node(4);
    root->right = new Node(20);
    root->right->left = new Node(13);
    root->right->right = new Node(70);
    bool res = check_for_balanced_binary_tree_naive(root);
    cout << res << " ";
    int res2 = check_for_balanced_binary_tree(root);
    cout << res2 << " ";
    return 0;
}