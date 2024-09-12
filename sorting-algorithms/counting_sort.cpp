// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

void CountingSort(int input_arr[], int range, int size)
{
    int output_arr[size];
    int count_arr[range] = {0};

    for (int i = 0; i < size; ++i)
    {
        ++count_arr[input_arr[i]];
    }

    for (int i = 1; i < range; ++i)
    {
        count_arr[i] += count_arr[i - 1];
    }

    for (int i = 0; i < size; ++i)
    {
        output_arr[--count_arr[input_arr[i]]] = input_arr[i];
    }

    for (int i = 0; i < size; ++i)
    {
        input_arr[i] = output_arr[i];
    }
}

int main()
{
    int size, range;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int arr[size];

    cout << "Enter the range of the elements" << endl;
    cin >> range;

    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    CountingSort(arr, range, size);

    for (int var : arr)
    {
        cout << var << " ";
    }

    return 0;
}