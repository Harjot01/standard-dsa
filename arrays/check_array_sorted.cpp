// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

struct Array
{
    int A[10];
    int length;
    int size;
};

void Display(Array &arr)
{
    for (int i = 0; i < arr.length; ++i)
    {
        cout << arr.A[i] << " ";
    }
    cout << "\n";
}

void InsertionInSortedArray(Array &arr, int elt)
{
    int i = arr.length - 1;
    while (arr.A[i] > elt)
    {
        arr.A[i + 1] = arr.A[i];
        i--;
    }
    arr.A[i + 1] = elt;
    arr.length++;
}

bool isSorted(Array &arr)
{
    for (int i = 0; i < arr.length - 1; ++i)
    {
        if (arr.A[i] > arr.A[i + 1])
            return false;
    }
    return true;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Rearrange(Array &arr)
{
    int i = 0, j = arr.length - 1;
    while (i < j)
    {
        while (arr.A[i] < 0)
            i++;
        while (arr.A[j] >= 0)
            j--;
        if (i < j)
            swap(arr.A[i], arr.A[j]);
    }
}

int main()
{
    Array arr = {{-1, 2, 5, 7, -13, 14, -16}, 7, 10};
    Rearrange(arr);
    Display(arr);
    return 0;
}