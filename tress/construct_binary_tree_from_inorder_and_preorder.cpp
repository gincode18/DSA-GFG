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

void inorder_print(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    inorder_print(head->left);
    cout << head->data << " ";
    inorder_print(head->right);
}

int pre_order_index = 0;

Node *construct_binary_tree_from_inorder_and_preorder(int inorder[], int preorder[], int is, int ie)
{
    if (is > ie)
    {
        return NULL;
    }
    Node *root = new Node(preorder[pre_order_index]);
    pre_order_index++;

    int key_index;

    for (int i = is; i <= ie; i++)
    {
        if (root->data == inorder[i])
        {
            key_index = i;
            break;
        }
    }

    root->left = construct_binary_tree_from_inorder_and_preorder(inorder, preorder, is, key_index - 1);
    root->right = construct_binary_tree_from_inorder_and_preorder(inorder, preorder, key_index + 1, ie);

    return root;
}

int main()
{
    int inorder[] = {40, 20, 60, 50, 70, 10, 80, 100};
    int preorder[] = {10, 20, 40, 50, 60, 70, 80, 100};
    int n = sizeof(preorder) / sizeof(int);
    Node *res = construct_binary_tree_from_inorder_and_preorder(inorder, preorder, 0, n - 1);
    inorder_print(res);
    return 0;
}