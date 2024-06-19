#include <iostream>
using namespace std;

bool check_for_rotation(string txt, string pat)
{
    if (txt.length() != pat.length())
    {
        return false;
    }
    txt = txt + txt;
    if (txt.find(pat) != string::npos)
    {
        return true;
    }

    return false;
}

int main()
{
    string txt = "vishal";
    string pat = "shalza";
    bool res = check_for_rotation(txt, pat);
    cout << res;
    return 0;
}