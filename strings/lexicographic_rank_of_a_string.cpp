#include <iostream>
#define CHAR 256
using namespace std;

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}
int lexicographic_rank_of_a_string(string str)
{
    int res = 1;
    int n = str.length();
    int factorial = fact(n);
    int count[CHAR] = {0};
    for (int i = 0; i < n; i++)
    {
        count[str[i]]++;
    }
    for (int i = 1; i < CHAR; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        factorial = factorial / (n - i);
        res = res + count[str[i] - 1] * factorial;
        for (int j = str[i]; j < CHAR; j++)
        {
            count[j]--;
        }
    }

    return res;
}

int main()
{
    string str = "string";
    int res = lexicographic_rank_of_a_string(str);
    cout << res;
    return 0;
}