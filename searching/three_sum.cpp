
#include <iostream>
using namespace std;

bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;
    sort(A, A + arr_size);
    for (int i = 0; i < arr_size - 2; i++)
    {
        l = i + 1;
        r = arr_size - 1;
        while (l < r)
        {
            if (A[i] + A[l] + A[r] == sum)
            {
                cout << "Triplet is" <<" "<< A[i]<<" " << A[l]<<" " << A[r];
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else
                r--;
        }
    }

    return false;
}

int main()
{
    int A[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);

    find3Numbers(A, arr_size, sum);

    return 0;
}
