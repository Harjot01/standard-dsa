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

void Reverse(Array &arr)
{
    for (int i = arr.length - 1; i >= 0; --i)
    {
        cout << arr.A[i] << " ";
    }
    cout << "\n";
}

void leftRotation(Array &arr)
{
    int i, k;
    cout << "Enter the number of times you want to perform left rotation" << endl;
    cin >> k;
    for (int r = 0; r < k; ++r)
    {
        int elt = arr.A[0];
        for (i = 0; i < arr.length - 1; ++i)
        {
            arr.A[i] = arr.A[i + 1];
        }
        arr.A[i] = elt;
    }
}

void rightRotation(Array &arr)
{
    int i, k;
    cout << "Enter the number of times you want to peform right rotation" << endl;
    cin >> k;
    for (int r = 0; r < k; ++r)
    {
        int elt = arr.A[arr.length - 1];
        for (i = arr.length - 1; i > 0; --i)
        {
            arr.A[i] = arr.A[i - 1];
        }
        arr.A[i] = elt;
    }
}

int main()
{
    Array arr = {{1, 2, 5, 7, 13, 14, 16}, 7, 10};
    Display(arr);
    return 0;
}