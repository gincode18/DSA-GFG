#include <iostream>
#include <queue>
using namespace std;

void generate_numbers_with_given_digits(int n)
{
    queue<string> q;
    q.push("5");
    q.push("6");

    for (int i = 0; i < n; i++)
    {
        string front = q.front();
        cout << front << " ";

        q.pop();
        q.push(front + "5");
        q.push(front + "6");
    }
}

void generate_binary_number(int n)
{
    queue<string> q;
    q.push("1");

    for (int i = 0; i < n; i++)
    {
        string front = q.front();
        cout << front << " ";

        q.pop();
        q.push(front + "0");
        q.push(front + "1");
    }
}

int main()
{
    int n = 5;
    generate_numbers_with_given_digits(n);
    cout << "\n";
    generate_binary_number(n);
    return 0;
}