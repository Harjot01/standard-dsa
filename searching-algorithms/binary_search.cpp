// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

// Best case time complexity = O(1);
// Worst case time complexity = O(logn)

void BinarySearch(int arr[], int size, int elt)
{
    int left = 0, right = size - 1, mid, temp = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == elt)
        {
            cout << "Element found at position: " << mid << endl;
            temp = 0;
            break;
        }
        else if (arr[mid] < elt)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (temp == -1)
    {
        cout << "Element not found" << endl;
    }
}

int main()
{
    int size, elt;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element to search" << endl;
    cin >> elt;

    BinarySearch(arr, size, elt);
    return 0;
}