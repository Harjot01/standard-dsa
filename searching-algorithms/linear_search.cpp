// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

void LinearSearch(int a[], int elt, int size)
{
    int temp = -1;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == elt)
        {
            cout << "Element found at position: " << i + 1 << endl;
            temp = 0;
            break;
        }
    }
    if (temp == -1)
    {
        cout << "No Element Found" << endl;
    }
}

int main()
{
    int n, elt;
    cout << "Enter the number of elements in the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter an element to search" << endl;
    cin >> elt;

    LinearSearch(arr, elt, n);

    return 0;
}