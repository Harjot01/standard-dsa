// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

class MinHeap
{
public:
    int *harr;
    int heap_capacity;
    int heap_size;

    MinHeap(int capacity)
    {
        this->heap_size = 0;
        this->heap_capacity = capacity;
        harr = new int[heap_capacity];
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    int getMin()
    {
        return harr[0];
    }

    void LinearSearch(int val)
    {
        for (int i = 0; i < heap_size; ++i)
        {
            if (harr[i] == val)
            {
                cout << "Value Found" << endl;
                return;
            }
        }
        cout << "Value not Found" << endl;
    }

    void InsertKey(int key)
    {
        if (heap_size == heap_capacity)
        {
            cout << "Heap is Full" << endl;
            return;
        }
        heap_size++;
        int i = heap_size - 1;
        harr[i] = key;
        while (i != 0 and harr[parent(i)] > harr[i])
        {
            Swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }

    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size and harr[l] < harr[i])
            smallest = l;
        if (r < heap_size and harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    int ExtractMin()
    {
        if (heap_size <= 0)
            return INT_MAX;
        else if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }
        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);
        return root;
    }

    void DecreaseKey(int i, int value)
    {
        harr[i] = value;
        while (i != 0 and harr[parent(i)] > harr[i])
        {
            Swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }

    void DeleteKey(int i)
    {
        DecreaseKey(i, INT_MIN);
        ExtractMin();
    }

    void HeapSort()
    {
        int temp[heap_capacity];
        for (int i = 0; i < heap_capacity; ++i)
        {
            temp[i] = ExtractMin();
        }

        for (int i = 0; i < heap_capacity; ++i)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }

    void PrintArray()
    {
        for (int i = 0; i < heap_size; ++i)
            cout << harr[i] << " ";
        cout << endl;
    }
};

int main()
{
    int capacity;
    cout << "Enter the size of the heap" << endl;
    cin >> capacity;

    MinHeap h(capacity);

    h.InsertKey(9);
    h.InsertKey(5);
    h.InsertKey(22);
    h.InsertKey(12);
    h.InsertKey(16);

    cout << "The unsorted array is: " << endl;
    h.PrintArray();

    for (int i = capacity / 2 - 1; i >= 0; i--)
    {
        h.MinHeapify(i);
    }

    cout << "The sorted array is: " << endl;
    h.HeapSort();
    return 0;
}