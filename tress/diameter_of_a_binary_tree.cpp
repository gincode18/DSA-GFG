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

int diameter_of_a_binary_tree_naive(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int diameter = 1 + height_of_binary_tree(root->left) + height_of_binary_tree(root->right);
    int left_diametre = diameter_of_a_binary_tree_naive(root->left);
    int right_diametre = diameter_of_a_binary_tree_naive(root->right);

    return max(diameter, max(left_diametre, right_diametre));
}

int res = 0;

int diameter_of_a_binary_tree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left_diameter = diameter_of_a_binary_tree(root->left);
    int right_diameter = diameter_of_a_binary_tree(root->right);
    int diameter = left_diameter + right_diameter + 1;

    res = max(res, diameter);

    return 1 + max(left_diameter, right_diameter);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->left->left = new Node(60);

    int res1 = diameter_of_a_binary_tree_naive(root);
    cout << res1 << "\n";

    diameter_of_a_binary_tree(root);
    cout << res;
    return 0;
}