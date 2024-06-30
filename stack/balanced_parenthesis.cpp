#include <iostream>
#include <stack>
using namespace std;

bool is_similar(char a, char b)
{
    if (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}')
    {
        return true;
    }
    return false;
}

bool balanced_parenthesis(string str, int n)
{
    stack<char> s;
    for (auto character : str)
    {
        if (character == '(' || character == '[' || character == '{')
        {
            s.push(character);
        }
        else
        {
            if (!s.empty() || is_similar(s.top(), character))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return s.empty();
}

int main()
{
    string str = "[({})]";
    bool res = balanced_parenthesis(str, str.length());
    cout << res << " ";
    return 0;
}