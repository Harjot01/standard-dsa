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
    cout << "Displaying all the elements inside the array"
         << "\n";
    for (int i = 0; i < arr.size; ++i)
    {
        cout << arr.A[i] << " ";
    }
    cout << "\n";
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x; 
    *x = *y;
    *y = temp;
}

int LinearSearch(Array *arr, int key)
{
    for (int i = 0; i < arr->size; ++i)
    {
        if (key == arr->A[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    cout << LinearSearch(&arr, 4) << "\n";

    Display(arr);

    cout << LinearSearch(&arr, 6);

    Display(arr);
    return 0;
}