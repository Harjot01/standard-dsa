// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(Array *arr)
{
    for (int i = 0; i < arr->length; ++i)
    {
        cout << arr->A[i] << " ";
    }
}

bool LinearSearchBool(Array *arr, int elt)
{
    for (int i = 0; i < arr->length; ++i)
    {
        if (arr->A[i] == elt)
        {
            return true;
            break;
        }
    }
    return false;
}

// Solution in O(n2)
struct Array *Union(Array *arr1, Array *arr2)
{
    Array *arr3;
    int k = 0;
    arr3 = (struct Array *)malloc(sizeof(Array));
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    for (int i = 0; i < arr1->length; ++i)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (int i = 0; i < arr3->size; ++i)
    {
        if (!LinearSearchBool(arr3, arr2->A[i]))
            arr3->A[k++] = arr2->A[i];
    }
    return arr3;
}

// Solution in O(n)
struct Array *Merge_Union(Array *arr1, Array *arr2)
{
    Array *arr3;
    int i, j, k;
    i = j = k = 0;
    arr3 = (struct Array *)malloc(sizeof(Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; ++i)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; ++j)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

// Solution in O(n2)
struct Array *Intersection(Array *arr1, Array *arr2)
{
    Array *arr3;
    int j = 0;
    arr3 = (struct Array *)malloc(sizeof(Array));
    for (int i = 0; i < arr1->length; i++)
    {
        if (LinearSearchBool(arr2, arr1->A[i]))
            arr3->A[j++] = arr1->A[i];
    }

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

// Solution in O(n)
struct Array *Merge_Intersection(Array *arr1, Array *arr2)
{
    Array *arr3;
    int i, j, k;
    i = j = k = 0;
    arr3 = (struct Array *)malloc(sizeof(Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        else
            j++;
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

// Solution in O(n2)
struct Array *Difference(Array *arr1, Array *arr2)
{
    Array *arr3;
    int j = 0;
    arr3 = (struct Array *)malloc(sizeof(Array));
    for (int i = 0; i < arr1->length; i++)
    {
        if (!LinearSearchBool(arr2, arr1->A[i]))
            arr3->A[j++] = arr1->A[i];
    }

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

// Solution in O(n)
struct Array *Merge_Difference(Array *arr1, Array *arr2)
{
    Array *arr3;
    int i, j, k;
    i = j = k = 0;
    arr3 = (struct Array *)malloc(sizeof(Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else
            i++, j++;
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

int main()
{
    Array arr1 = {{3, 4, 5, 6, 10}, 10, 5};
    Array arr2 = {{2, 4, 5, 7, 12}, 10, 5};
    Array *arr3 = Merge_Difference(&arr1, &arr2);
    Display(arr3);

    return 0;
}