// Life is not a problem to be solved, it is a game to be played
#include <bits/stdc++.h>
using namespace std;
template <class T>
class Stack
{
private:
    int top;
    int capacity;
    T arr[];

public:
    Stack(int capacity)
    {
        top = -1;
        this->capacity = capacity;
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (top == capacity - 1)
            return true;
        else
            return false;
    }

    void Push(T val)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    T Pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            T poped_val = arr[top];
            arr[top] = 0;
            top--;
            return poped_val;
        }
    }

    int Peek(int index)
    {
        if (index >= 0 && index < capacity)
        {
            return arr[index];
        }
        else
        {
            cout << "Invalid Index" << endl;
        }
    }

    int count()
    {
        return (++top);
    }

    void change(int index, T val)
    {
        if (index >= 0 && index < capacity)
        {
            arr[index] = val;
            cout << "Value changed at Position " << index << endl;
        }
        else
        {
            cout << "Invalid Index" << endl;
        }
    }

    void display()
    {
        cout << "Displaying Values in the Stack" << endl;
        for (int i = capacity - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements in the Stack" << endl;
    cin >> n;
    Stack<int> s(n);
    int option, position;
    float value;
    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl;
        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Push Function Called - " << endl;
            cout << "Enter the value to Push in the Stack" << endl;
            cin >> value;
            s.Push(value);
            break;

        case 2:
            cout << "Pop Function Called - Poped value: " << s.Pop() << endl;
            break;

        case 3:
            if (s.isEmpty())
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                cout << "Stack is not Empty" << endl;
            }
            break;

        case 4:
            if (s.isFull())
            {
                cout << "Stack is Full" << endl;
            }
            else
            {
                cout << "Stack is not Full" << endl;
            }
            break;

        case 5:
            cout << "Peek Function Called - " << endl;
            cout << "Enter the Index of the element you want to see" << endl;
            cin >> position;
            cout << "The value at index " << position << " is " << s.Peek(position) << endl;
            break;

        case 6:
            cout << "Count Function Called - " << endl;
            cout << "The Total Size of the Stack is " << s.count() << endl;
            break;

        case 7:
            cout << "Change Function Called - " << endl;
            cout << "Enter the Index of the element that you want to change" << endl;
            cin >> position;
            cout << "Enter the Value that you want to change" << endl;
            cin >> value;
            s.change(position, value);
            break;

        case 8:
            cout << "Display Function Called - " << endl;
            s.display();
            break;

        case 9:
            system("clear");
            break;

        default:
            cout << "Enter the proper option number" << endl;
            break;
        }
    } while (option != 0);

    return 0;
}