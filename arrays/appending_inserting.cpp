// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(Array arr)
{
    cout << "Displaying all the elements inside the array" << endl;
    for (int i = 0; i < arr.size; ++i)
    {
        cout << arr.A[i] << " ";
    }
}

void Append(Array *arr, int elt)
{
    if (arr->length < arr->size)
        arr->A[arr->length] = elt;
        arr->length++;
}

void Insert(Array *arr, int index, int elt)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = elt;
        arr->length++;
    }
    else
    {
        cout << "Invalid Index" << endl;
    }
}

int main()
{
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    Append(&arr, 10);
    Append(&arr, 11);
    Insert(&arr, 0, 13);
    Display(arr);

    return 0;
}