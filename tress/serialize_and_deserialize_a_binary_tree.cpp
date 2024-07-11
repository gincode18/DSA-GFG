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

void serialize_a_binary_tree(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        arr.push_back(-1);
        return;
    }

    arr.push_back(root->data);
    serialize_a_binary_tree(root->left, arr);
    serialize_a_binary_tree(root->right, arr);
}

Node *deserialize_a_binary_tree(vector<int> &arr, int &index)
{
    if (index == arr.size())
    {
        return NULL;
    }

    int val = arr[index];
    index++;
    
    if (val == -1)
    {
        return NULL;
    }

    Node *root = new Node(val);
    root->left = deserialize_a_binary_tree(arr, index);
    root->right = deserialize_a_binary_tree(arr, index);

    return root;
}

int main()
{
    /*    1
        /   \
       2     3
      / \     \
     4   5     6
    / \       / \
   7   8     9  10
   */
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
    vector<int> arr;
    serialize_a_binary_tree(root, arr);

    for (auto num : arr)
    {
        cout << num << " ";
    }
    cout << "\n";

    int index = 0;
    Node *res = deserialize_a_binary_tree(arr, index);
    inorder(res);

    return 0;
}