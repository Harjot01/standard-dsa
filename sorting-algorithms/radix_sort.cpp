// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

void CountingSort(int input_arr[], int size, int div)
{
    int output_arr[size];
    int count_arr[10] = {0};

    for (int i = 0; i < size; ++i)
    {
        count_arr[(input_arr[i] / div) % 10]++;
    }

    for (int i = 1; i < 10; ++i)
    {
        count_arr[i] += count_arr[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output_arr[count_arr[(input_arr[i] / div) % 10] - 1] = input_arr[i];
        count_arr[(input_arr[i] / div) % 10]--;
    }

    for (int i = 0; i < size; ++i)
    {
        input_arr[i] = output_arr[i];
    }
}

int GetMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void RadixSort(int arr[], int size)
{
    int m = GetMax(arr, size);
    for (int div = 1; m / div > 0; div *= 10)
    {
        CountingSort(arr, size, div);
    }
}

int main()
{
    int size;
    cout << "Enter the total size of the array" << endl;
    cin >> size;
    int arr[size];

    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    RadixSort(arr, size);
    cout << "After Sorting the Array" << endl;

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}