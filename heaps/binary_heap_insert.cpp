#include <iostream>
using namespace std;

class heap
{
public:
    int size, capacity, *arr;
    heap(int c);
    int left(int i);
    int right(int i);
    int parent(int i);
    void insert(int data);
    void print();
    void heapify(int i);
    int extract_min();
};

heap::heap(int c)
{
    this->arr = new int[c];
    this->size = 0;
    this->capacity = c;
}

int heap::left(int i)
{
    return (2 * i + 1);
}

int heap::right(int i)
{
    return (2 * i + 2);
}

int heap::parent(int i)
{
    return (i - 1) / 2;
}

void heap::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heap::insert(int data)
{
    if (size < capacity)
    {
        int i = size;
        arr[size] = data;
        size++;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    else
    {
        cout << "Heap is full!" << endl;
    }
}

int main()
{
    heap h(11);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(20);

    h.print();

    return 0;
}
