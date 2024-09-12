// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

struct Array
{
    int A[15];
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

int BinarySearch(Array &arr, int key)
{
    int left = 0;
    int right = arr.size - 1;
    int mid, found = 0;

    while (right >= left)
    {
        mid = (left + right) / 2;

        if (arr.A[mid] == key)
        {
            cout << "Search Successfull"
                 << "\n";
            return mid;
        }

        else if (arr.A[mid] > key)
        {
            right = mid - 1;
        }

        else
        {
            left = mid + 1;
        }
    }
    return -1;
}  

int RBinarySearch(Array &arr, int left, int right, int key)
{
    int mid = (left + right) / 2;
    if (right >= left)
    {
        if (arr.A[mid] == key) 
        {
            cout << "Search Successfull"
                 << "\n";
            return mid;
        }
        else if (arr.A[mid] > key)
            return RBinarySearch(arr, left, mid - 1, key);
        else
            return RBinarySearch(arr, mid + 1, right, key);
    }
    return -1;
}

int main()
{
    Array arr = {{4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43}, 15, 5};

    Display(arr);
    int low = 0;
    int high = arr.size - 1;
    cout << "Result using Iterative Approach " << BinarySearch(arr, 21) << "\n";
    cout << "Result using Recursive Approach " << RBinarySearch(arr, low, high, 38);
    return 0;
}