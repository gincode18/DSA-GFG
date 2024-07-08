#include <iostream>
#include <queue>
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

void print_left_view_of_binary_tree(Node *root)
{
    queue<Node *> q;

    q.push(root);
    while (!q.empty())

    {
        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            Node *front = q.front();

            if (i == 0)
            {
                cout << front->data << " ";
            }

            q.pop();

            if (front->left != NULL)
            {
                q.push(front->left);
            }

            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
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
    print_left_view_of_binary_tree(root);
    return 0;
}