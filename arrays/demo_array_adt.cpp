// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(Array arr)
{
    printf("Displaying all the elements inside the array\n");
    for (int i = 0; i < arr.length; ++i)
    {
        printf("%d ", arr.A[i]);
    }
}

int main()
{
    Array arr;
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &arr.size);
    arr.A = new int[arr.size];
    arr.length = 0;

    printf("Enter the total elements you want to insert\n");
    scanf("%d", &n);

    printf("Enter the elements of the array\n");

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr.A[i]);
    }

    arr.length = n;

    Display(arr);

    return 0;
}