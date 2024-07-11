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

bool find_path(Node *root, vector<Node *> &p, int n)
{
    if (root == NULL)
    {
        return false;
    }

    p.push_back(root);

    if (root->data == n)
    {
        return true;
    }

    if (find_path(root->left, p, n) || find_path(root->right, p, n))
    {
        return true;
    }
    p.pop_back();

    return false;
}

Node *lca_of_binary_tree_naive(Node *root, int n1, int n2)
{
    vector<Node *> p1, p2;

    if (find_path(root, p1, n1) == false || find_path(root, p2, n2) == false)
    {
        return NULL;
    }

    Node *res = p1[0];
    for (int i = 0; i < p1.size() && i < p2.size(); i++)
    {
        if (p1[i]->data == p2[i]->data)
        {
            res = p1[i];
        }
        else
        {
            break;
        }
    }

    return res;
}

Node *lca_of_binary_tree(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *left_lca = lca_of_binary_tree(root->left, n1, n2);
    Node *right_lca = lca_of_binary_tree(root->right, n1, n2);

    if (left_lca != NULL && right_lca != NULL)
    {
        return root;
    }

    if (left_lca != NULL)
    {
        return left_lca;
    }

    else
    {
        return right_lca;
    }
}

int main()
{
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
    Node *res = lca_of_binary_tree_naive(root, 5, 7);
    cout << res->data << " ";
    res = lca_of_binary_tree(root, 5, 7);
    cout << res->data << " ";
    return 0;
}