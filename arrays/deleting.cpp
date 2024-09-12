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
        arr->A[arr->length++] = elt;
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

int Delete(Array *arr, int index)
{
    if (index >= 0 && index <= arr->length)
    {
        int x = arr->A[index];
        for (int i = index; i < arr->length; ++i)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int main()
{
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    // Calling Delete function
    cout << "The value deleted from the array is " << Delete(&arr, 1) << endl;
    Display(arr);

    return 0;
}