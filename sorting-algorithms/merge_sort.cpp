// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[], int l, int mid, int r, int size)
{
    int temp[size];
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++, k++;
        }
        else
        {
            temp[k] = arr[j];
            j++, k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++, k++;
    }
    while (j <= r)
    {
        temp[k] = arr[j];
        j++, k++;
    }

    for (int p = l; p <= r; ++p)
    {
        arr[p] = temp[p];
    }
}

void MergeSort(int arr[], int l, int r, int size)
{
    int mid;
    if (l < r)
    {
        mid = (l + r) / 2;
        MergeSort(arr, l, mid, size);
        MergeSort(arr, mid + 1, r, size);
        Merge(arr, l, mid, r, size);
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    MergeSort(arr, 0, size - 1, size);

    for (int var : arr)
    {
        cout << var << " ";
    }
    return 0;
}