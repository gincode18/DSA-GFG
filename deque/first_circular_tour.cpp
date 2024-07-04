#include <iostream>
#include <deque>
using namespace std;

int first_circular_tour_naive(int petrol[], int dist[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr_petrol = 0;
        int j = i;
        while (true)
        {
            curr_petrol += petrol[j] - dist[j];
            j = (j + 1) % n;
            if (curr_petrol < 0)
            {
                break;
            }
            if (i == j)
            {
                return i;
            }
        }
    }
    return -1;
}

int first_circular_tour_deque(int petrol[], int dist[], int n)
{
    deque<int> dq;
    int curr_petrol = 0;

    for (int i = 0; i < n; i++)
    {
        dq.push_back(i);
        curr_petrol += petrol[i] - dist[i];

        while (curr_petrol < 0)
        {
            int front = dq.front();
            dq.pop_front();

            curr_petrol = curr_petrol - (petrol[front] - dist[front]);
        }
    }

    if (curr_petrol >= 0 && !dq.empty())
    {
        return dq.front();
    }

    return -1; // No tour possible
}

int first_circular_tour(int petrol[], int dist[], int n)
{
    int curr_petrol = 0, pre_petrol = 0, j = 0;

    for (int i = 0; i < n; i++)
    {
        curr_petrol = curr_petrol + petrol[i] - dist[i];
        if (curr_petrol < 0)
        {
            pre_petrol += curr_petrol;
            curr_petrol = 0;
            j = i + 1;
        }
    }

    return (curr_petrol + pre_petrol) <= 0 ? -1 : j;
}

int main()
{
    // int petrol[] = {4, 8, 7, 4};
    // int dist[] = {6, 5, 3, 5};
    int petrol[] = {50, 10, 60, 100};
    int dist[] = {30, 20, 100, 10};
    int n = sizeof(petrol) / sizeof(int);

    int res = first_circular_tour_naive(petrol, dist, n);
    cout << res << " ";

    res = first_circular_tour_deque(petrol, dist, n);
    cout << res << " ";

    res = first_circular_tour(petrol, dist, n);
    cout << res << " ";

    return 0;
}