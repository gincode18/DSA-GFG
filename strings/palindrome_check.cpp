#include <iostream>
using namespace std;

int palindrome_check(string str)
{
    int low = 0;
    int high = (int)str.length() - 1;
    while (low < high)
    {
        if (str[low] == str[high])
        {
            low++;
            high--;
        }
        else
        {
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
    return 0;
}

int main()
{
    string str = "aabaa";
    palindrome_check(str);
    return 0;
}
