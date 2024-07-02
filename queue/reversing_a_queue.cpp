#include <iostream>
#include <queue>
using namespace std;

int reversing_a_queue(queue<int> &q)
{
    if (q.empty())
    {
        return 0;
    }

    int front = q.front();
    q.pop();

    reversing_a_queue(q);
    q.push(front);

    return 0;
}
int print_queue(queue<int> q)
{
    if (q.empty())
    {
        return 0;
    }

    cout << q.front() << " ";
    q.pop();
    return print_queue(q);
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Before" << " :";
    print_queue(q);
    reversing_a_queue(q);
    cout << "\n"
         << "After" << " :";
    print_queue(q);
    return 0;
}