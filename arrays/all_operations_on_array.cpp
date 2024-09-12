// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    int A[10];
    int capacity;
    int length;
};

void Display(Array *arr)
{
    cout << "Displaying all the elements inside the array"
         << "\n";
    for (int i = 0; i < arr->length; ++i)
    {
        cout << arr->A[i] << " ";
    }
    cout << "\n";
}

void Append(Array *arr, int elt)
{
    if (arr->length < arr->capacity)
        arr->A[arr->length++] = elt;
}

void Insert(Array *arr, int index, int elt)
{
    if (index >= 0 && index <= arr->length - 1)
    {
        for (int i = arr->length; i > index; --i)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = elt;
        arr->length++;
    }
    else
    {
        cout << "Invalid Index"
             << "\n";
    }
}

int Delete(Array *arr, int index)
{
    if (index >= 0 && index <= arr->length - 1)
    {
        int x = arr->A[index];
        for (int i = index; i < arr->length; ++i)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    else
    {
        cout << "Invalid Index"
             << "\n";
        return 0;
    }
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int LinearSearch(Array *arr, int elt)
{
    for (int i = 0; i < arr->length; ++i)
    {
        if (arr->A[i] == elt)
        {
            Swap(&arr->A[i], &arr->A[0]); // Making Linear Search Efficient
            cout << "Element found at index ";
            return i;
        }
    }
    cout << "Element not found"
         << "\n";
    return -1;
}

int BinarySearch(Array *arr, int elt)
{
    int left = 0;
    int right = arr->length - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr->A[mid] == elt)
        {
            cout << "Element found at index ";
            return mid;
        }

        else if (arr->A[mid] > elt)
        {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << "Element not found ";
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


// Code for right rotation
void RightRotation(Array *arr)
{
    int i;
    int elt = arr->A[arr->length - 1]; // accessing the last element of the array

    // now using a for loop we are moving the elements towards right
    for (int i = arr->length - 1; i > 0; --i)
    {
        arr->A[i] = arr->A[i - 1];
    }

    arr->A[i] = elt; // now finally we are inserting the last element at first index
}


// Code for left rotation
void LeftRotation(Array *arr)
{
    int i;
    int elt = arr->A[0]; // accessing the first element of the array

    // now using a for loop we are moving the elements towards left
    for (i = 0; i < arr->length - 1; ++i)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[i] = elt; // now finally we are inserting the first element at last index
}

Array *Merge(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; ++i)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; ++j)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->capacity = 10;
    return arr3;
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
    arr3->capacity = 10;

    for (int i = 0; i < arr1->length; ++i)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (int i = 0; i < arr3->capacity; ++i)
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
    arr3->capacity = 10;
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
    arr3->capacity = 10;

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
    arr3->capacity = 10;
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
    arr3->capacity = 10;

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
    arr3->capacity = 10;
    return arr3;
}

int main()
{
    Array arr1 = {{3, 4, 5, 6, 10}, 10, 5};
    Array arr2 = {{2, 4, 5, 7, 12}, 10, 5};
    Array *arr3;

    int choice, index, value;
    do
    {
        
        cout << "Press 0 to Exit"
             << "\n";
        cout << "Press 1 to Insert"
             << "\n";
        cout << "Press 2 to Append"
             << "\n";
        cout << "Press 3 to Delete"
             << "\n";
        cout << "Press 4 to Use Linear Search"
             << "\n";
        cout << "Press 5 to Use Binary Search"
             << "\n";
        cout << "Press 6 to Display"
             << "\n";
        cout << "Press 7 to Rotate elements towards Left in Array"
             << "\n";
        cout << "Press 8 to Rotate elements towards Right in Array"
             << "\n";
        cout << "Press 9 to Merge two Arrays"
             << "\n";
        cout << "Press 10 for Union of two Arrays"
             << "\n";
        cout << "Press 11 for Intersection of two Arrays"
             << "\n";
        cout << "Press 12 for Difference of two Arrays"
             << "\n";
        cout << "Press 13 to Clear Screen"
             << "\n";

        cout << "Enter your choice"
             << "\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;

        case 1:
            cout << "Insert Function Called..."
                 << "\n";
            cout << "Enter the index and value"
                 << "\n";
            cin >> index >> value;
            Insert(&arr1, index, value);
            break;

        case 2:
            cout << "Append Function Called..."
                 << "\n";
            cout << "Enter the value to append in the array"
                 << "\n";
            cin >> value;
            Append(&arr1, value);
            break;

        case 3:
            cout << "Delete Function Called..."
                 << "\n";
            cout << "Enter the index to delete the element"
                 << "\n";
            cin >> index;
            cout << "Value deleted: " << Delete(&arr1, index) << "\n";
            break;

        case 4:
            cout << "Linear Search Algorithm Called..."
                 << "\n";
            cout << "Enter the element to search in the array"
                 << "\n";
            cin >> value;
            cout << LinearSearch(&arr1, value) << "\n";
            break;

        case 5:
            cout << "Binary Search Algorithm Called..."
                 << "\n";
            cout << "Enter the element to search in the array"
                 << "\n";
            cin >> value;
            cout << BinarySearch(&arr1, value) << "\n";
            break;

        case 6:
            cout << "Display Function Called..."
                 << "\n";
            Display(&arr1);
            break;

        case 7:
            cout << "Left Rotation Function Called..."
                 << "\n";
            LeftRotation(&arr1);
            break;

        case 8:
            cout << "Right Rotation Function Called..."
                 << "\n";
            RightRotation(&arr1);
            break;

        case 9:
            cout << "Merge Function Called..."
                 << "\n";
            arr3 = Merge(&arr1, &arr2);
            break;

        case 10:
            cout << "Union Function Called..."
                 << "\n";
            arr3 = Merge_Union(&arr1, &arr2);
            Display(arr3);
            break;

        case 11:
            cout << "Intersection Function Called..."
                 << "\n";
            arr3 = Merge_Intersection(&arr1, &arr2);
            Display(arr3);
            break;

        case 12:
            cout << "Difference Function Called..."
                 << "\n";
            arr3 = Merge_Difference(&arr1, &arr2);
            Display(arr3);
            break;

        case 13:
            cout << "Clear Screen Function Called..."
                 << "\n";
            system("clear");
            break;

        default:
            break;
        }
    } while (choice != 0);

    return 0;
}