// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

int Get(Array &arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    else
    {
        cout << "Invalid Index" << endl;
        return -1;
    }
}

void Set(Array &arr, int index, int value)
{
    if (index >= 0 && index < arr.length)
        arr.A[index] = value;
    else
    {
        cout << "Invalid Index" << endl;
        return;
    }
}

int Max(Array &arr)
{
    int maxi = arr.A[0];
    for (int i = 1; i < arr.length; ++i)
    {
        if (arr.A[i] > maxi)
            maxi = arr.A[i];
    }
    return maxi;
}

int Min(Array &arr)
{
    int mini = arr.A[0];
    for (int i = 1; i < arr.length; ++i)
    {
        if (arr.A[i] < mini)
            mini = arr.A[i];
    }
    return mini;
}

int Sum(Array &arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; ++i)
    {
        sum += arr.A[i];
    }
    return sum;
}

int RSum(Array &arr, int n)
{
    if (n < 0)
        return 0;
    else
        return RSum(arr, n - 1) + arr.A[n]; // Recursive Function for same
}

float Average(Array &arr)
{
    return (float)Sum(arr) / arr.length;
}

int main()
{
    Array arr = {{2, 3, 4, 5, 6}, 5, 5};

    cout << "The Sum of the elements of the array is " << Average(arr);
    return 0;
}