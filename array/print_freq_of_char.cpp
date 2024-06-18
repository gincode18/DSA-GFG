#include <iostream>
#include <string>
using namespace std;

int print_freq_of_char(string str)
{
    int arr[26] = {0};
    int n = sizeof(arr) / sizeof(int);
    for (auto character : str)
    {
        arr[(int)character - (int)'a'] += 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            cout << char(i + 97) << " " << arr[i] << "\n";
        }
    }

    return 0;
}

int main()
{
    string str = "vishal";
    print_freq_of_char(str);
    return 0;
}