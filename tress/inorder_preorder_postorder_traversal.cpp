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

void inorder(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    inorder(head->left);
    cout << head->data << " ";
    inorder(head->right);
}

void preorder(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    preorder(head->left);
    preorder(head->right);
}

void postorder(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    preorder(head->left);
    preorder(head->right);
    cout << head->data << " ";
}

int main()
{
    Node *head = new Node(10);
    head->left = new Node(5);
    head->right = new Node(20);
    inorder(head);
    cout << "\n";
    preorder(head);
    cout << "\n";
    postorder(head);
    return 0;
}