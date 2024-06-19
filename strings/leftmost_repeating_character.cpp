#include <iostream>
#include <unordered_map>
using namespace std;

int leftmost_repeating_character(string str1)
{
    unordered_map<char, int> map;
    for (auto character : str1)
    {
        map[character] += 1;
    }
    
    for (int i = 0; i < str1.length(); i++)
    {
        if (map[str1[i]] > 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string str1 = "abbcc";
    int res = leftmost_repeating_character(str1);
    cout << res;
    return 0;
}