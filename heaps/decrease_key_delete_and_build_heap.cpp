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
    void decrease_key(int index, int key);
    int delete_key(int index);
    int build_heap();
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

void heap::heapify(int i)
{
    int lt = left(i);
    int rt = right(i);
    int smallest = i;

    if (lt < size && arr[lt] < arr[smallest])
    {
        smallest = lt;
    }

    if (rt < size && arr[rt] < arr[smallest])
    {
        smallest = rt;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(smallest);
    }
}

int heap::extract_min()
{
    if (size == 0)
    {
        return -1;
    }

    if (size == 1)
    {
        size--;
        return arr[0];
    }

    int temp = arr[0];

    swap(arr[0], arr[size - 1]);
    size--;
    heapify(0);
    return temp;
}

void heap::decrease_key(int index, int key)
{
    arr[index] = key;
    while (index >= 0 && arr[parent(index)] > arr[index])
    {
        swap(arr[index], arr[parent(index)]);
        index = parent(index);
    }
}

int heap::delete_key(int index)
{
    int res = arr[index];
    decrease_key(index, INT_MIN);
    extract_min();

    return res;
};

int heap::build_heap()
{
    for (int i = (size - 2) / 2; i >= 0; i--)
    {
        heapify(i);
    }
}

int main()
{
    heap h(11);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(20);

    cout << h.delete_key(3) << "\n";
    h.print();

    return 0;
}
