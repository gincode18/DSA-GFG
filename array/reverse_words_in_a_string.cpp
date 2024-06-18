#include <iostream>
using namespace std;

string revese_words_in_a_string(string &str)
{
    int start = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            reverse(str.begin() + start, str.begin() + i);
            start = i + 1;
        }
    }
    reverse(str.begin() + start, str.end());
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    string str = "this is a test";
    string res = revese_words_in_a_string(str);
    cout << res;

    return 0;
}