#include <iostream>
#include <stack>

using namespace std;

class stack_with_get_min_pos_only
{
    stack<int> s;
    int min;

public:
    int getMin()
    {
        return min;
    }

    int peek()
    {
        int t = s.top();

        if (t <= 0)
        {
            return min;
        }
        else
        {
            return t;
        }
    }
    int pop()
    {
        int t = s.top();
        s.pop();

        if (t <= 0)
        {
            int res = min;
            min = min - t;
            return res;
        }
        else
        {
            return t;
        }
    }

    void push(int x)
    {

        if (x <= min)
        {
            s.push(x - min);
            min = x;
        }
        else
        {
            s.push(x);
        }
    }
};

class stack_with_get_min
{
    stack<int> s;
    int min;

public:
    int getMin()
    {
        return min;
    }

    int peek()
    {
        int t = s.top();

        if (t <= min)
        {
            return min;
        }
        else
        {
            return t;
        }
    }
    int pop()
    {
        int t = s.top();
        s.pop();

        if (t <= min)
        {
            int res = min;
            min = 2 * min - t;
            return res;
        }
        else
        {
            return t;
        }
    }

    void push(int x)
    {
        if (s.empty())
        {
            s.push(x);
            min = x;
        }

        else if (x <= min)
        {
            s.push(2 * x - min);
            min = x;
        }

        else
        {
            s.push(x);
        }
    }
};
int main()
{
    stack_with_get_min_pos_only s1;
    s1.push(5);
    s1.push(2);
    s1.push(1);
    cout << s1.getMin() << " ";
    s1.pop();
    cout << s1.getMin() << " ";
    s1.pop();
    cout << s1.getMin() << " ";

    stack_with_get_min s2;
    s2.push(5);
    s2.push(2);
    s2.push(1);
    cout << "\n"
         << s2.getMin() << " ";
    s2.pop();
    cout << s2.getMin() << " ";
    s2.pop();
    cout << s2.getMin() << " ";
    return 0;
}