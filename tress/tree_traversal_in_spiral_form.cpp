#include <iostream>
#include <queue>
#include <stack>
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

void tree_traversal_in_spiral_form(Node *root)
{
    stack<int> s;
    queue<Node *> q;

    q.push(root);
    bool reverse_order = false;

    while (!q.empty())
    {
        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            Node *front = q.front();

            q.pop();

            if (!reverse_order)
            {
                cout << front->data << " ";
            }
            else
            {
                s.push(front->data);
            }

            if (front->left != NULL)
            {
                q.push(front->left);
            }

            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
        if (reverse_order)
        {
            while (!s.empty())
            {
                cout << s.top() << " ";
                s.pop();
            }
        }

        reverse_order = !reverse_order;

        cout << "\n";
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
    tree_traversal_in_spiral_form(root);
    return 0;
}