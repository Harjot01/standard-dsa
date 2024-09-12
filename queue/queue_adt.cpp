// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int capacity;
    int arr[];

public:
    Queue() {}
    Queue(int capacity)
    {
        this->capacity = capacity;
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = 0;
        }
        front = rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (rear == capacity - 1 && front == 0)
            return true;
        else
            return false;
    }

    int enqueue(int value)
    {
        if (isFull())
        {
            return 0;
        }
        else if (isEmpty())
        {
            rear = front = 0;
            arr[rear] = value;
            return value;
        }
        else
        {
            rear++;
            arr[rear] = value;
            return value;
        }
    }

    int dequeue()
    {
        int x = 0;
        if (isEmpty())
        {
            return 0;
        }
        else if (front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            front = -1;
            rear = -1;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front++;
        }
        return x;
    }

    int count()
    {
        if(rear == -1 && front == -1)
            return 0;
        return ((rear - front) + 1);
    }

    void display()
    {
        cout << "Displaying all the values inside the queue" << endl;
        for (int i = 0; i < capacity; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the Queue" << endl;
    cin >> size;
    Queue obj(size);
    int option, value;
    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. enqueue()" << endl;
        cout << "2. dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl;

        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enqueue Function Called - " << endl;
            cout << "Enter the element to enqueue" << endl;
            cin >> value;
            cout << "Enqueued value: " << obj.enqueue(value) << endl;
            break;

        case 2:
            cout << "Dequeue Function Called - " << endl;
            cout << "Dequeued value: " << obj.dequeue() << endl;
            break;

        case 3:
            if (obj.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            break;

        case 4:
            if (obj.isFull())
                cout << "Queue is Full" << endl;
            else
                cout << "Queue is not Full" << endl;
            break;

        case 5:
            cout << "The Total elements in the Queue are " << obj.count() << endl;
            break;

        case 6:
            obj.display();
            break;

        case 7:
            system("clear");
            break;
        default:
            cout << "Invalid Option" << endl;
            break;
        }
    } while (option != 0);
    return 0;
}