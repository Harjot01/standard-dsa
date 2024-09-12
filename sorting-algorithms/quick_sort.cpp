// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;
    for (int i = s; i < e; ++i)
    {
        if (arr[i] <= pivot)
        {
            Swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    Swap(&arr[e], &arr[pIndex]);
    return pIndex;
}

void QuickSort(int arr[], int s, int e, int size)
{
    if (s < e)
    {
        int p = Partition(arr, s, e);
        QuickSort(arr, s, (p - 1), size);
        QuickSort(arr, (p + 1), e, size);
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    QuickSort(arr, 0, size - 1, size);

    for (int var : arr)
    {
        cout << var << " ";
    }
    return 0;
}