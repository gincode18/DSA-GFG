#include <iostream>
using namespace std;

int string_is_subsequence_of_other(string str1, string str2, int n, int m)
{
    int j = 0;
    for (int i = 0; i < (int)str1.length(); i++)
    {
        if (str1[i] == str2[j])
        {
            j++;
        }
    }
    if (j == (int)str2.length())
    {
        return true;
    }
    else
    {
        return false;
    }
    return 0;
}

bool rec_string_is_subsequence_of_other(string str1, string str2, int n, int m)
{
    if (m == 0)
    {
        return true;
    }
    else if (n == 0)
    {
        return false;
    }
    if (str1[m - 1] == str2[n - 1])
    {
        return rec_string_is_subsequence_of_other(str1, str2, n - 1, m - 1);
    }
    else
    {
        return rec_string_is_subsequence_of_other(str1, str2, n - 1, m);
    }
}

int main()
{
    string str1 = "vishal";
    string str2 = "vis";
    if (rec_string_is_subsequence_of_other(str1, str2, str1.length(), str2.length()))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }
    return 0;
}