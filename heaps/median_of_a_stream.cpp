#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    double data;
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

int counter = 0;

Node *find_kth_smallest_in_bst(Node *root, int k)
{
    if (root == NULL)
    {
        return root;
    }

    int counter = root->lcount + 1;

    if (k == counter)
    {
        return root;
    }

    if (counter > k)
    {
        return find_kth_smallest_in_bst(root->left, k);
    }
    // if u move to right root there all the nodes in left tree are samller than right BST
    return find_kth_smallest_in_bst(root->right, k - counter);
}

void median_of_a_stream_naive(double arr[], int n)
{
    Node *root = NULL;
    int size = 0;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
        size++;

        double res = 0;

        if (size % 2 == 0)
        {
            res = (find_kth_smallest_in_bst(root, size / 2)->data + find_kth_smallest_in_bst(root, size / 2 + 1)->data) / 2;
        }
        else
        {
            res = find_kth_smallest_in_bst(root, (size / 2) + 1)->data;
        }

        cout << res << " ";
    }
}

void median_of_a_stream(double arr[], int n)
{
    priority_queue<double> s;
    priority_queue<double, vector<double>, greater<double>> g;

    s.push(arr[0]);
    cout << arr[0] << " ";

    for (int i = 1; i < n; i++)
    {
        if (s.size() > g.size())
        {
            if (s.top() > arr[i])
            {
                g.push(s.top());
                s.pop();
                s.push(arr[i]);
            }
            else
            {
                g.push(arr[i]);
            }

            cout << (g.top() + s.top()) / 2 << " ";
        }
        else
        {
            if (arr[i] < s.top())
            {
                s.push(arr[i]);
            }

            else
            {
                g.push(arr[i]);
                s.push(g.top());
                g.pop();
            }

            cout << s.top() << " ";
        }
    }
}

int main()
{
    Node *root = NULL;
    double arr[] = {25, 7, 10, 15, 20};
    int n = sizeof(arr) / sizeof(double);

    median_of_a_stream_naive(arr, n);
    cout << endl;
    median_of_a_stream(arr, n);

    return 0;
}