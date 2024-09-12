// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

inline void Swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped)
        {
            break;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the total elements of the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    BubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}