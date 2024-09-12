// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int key, int data)
    {
        this->key = key;
        this->data = data;
        next = NULL;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;
    int itemCount;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    Queue(Node *n)
    {
        front = n;
        rear = n;
    }

    bool NodeExists(int key)
    {
        bool exists = false;
        Node *ptr = front;
        while (ptr != NULL)
        {
            if (ptr->key == key)
            {
                exists = true;
                break;
            }
            ptr = ptr->next;
        }
        return exists;
    }

    bool isEmpty()
    {
        if (front == NULL and rear == NULL)
            return true;
        else
            return false;
    }

    void Enqueue(Node *n)
    {
        if (isEmpty())
        {
            rear = n;
            front = n;
            cout << "Node Enqueued"
                 << "\n";
        }
        else if (NodeExists(n->key))
        {
            cout << "Node already exists with the key value of " << n->key << "\n";
        }
        else
        {
            rear->next = n;
            rear = n;
            cout << "Node Enqueued"
                 << "\n";
        }
    }

    Node *Dequeue()
    {
        Node *temp = NULL;
        if (isEmpty())
        {
            cout << "Queue is Empty"
                 << "\n";
        }
        else if (front == rear)
        {
            temp = front;
            front = NULL;
            rear = NULL;
            cout << "Node Dequeued"
                 << "\n";
        }
        else
        {
            temp = front;
            front = front->next;
            cout << "Node Dequeued"
                 << "\n";
        }
        return temp;
    }

    int Count()
    {
        int count = 0;
        Node *ptr = front;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty"
                 << "\n";
        }
        else
        {
            Node *ptr = front;
            while (ptr != NULL)
            {
                cout << "(" << ptr->key << ", " << ptr->data << ", " << ptr->next << ") --> ";
                ptr = ptr->next;
            }
            cout << "\n";
        }
    }
};

int main()
{
    Queue obj;
    Node *temp;
    int option, value, key;
    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit."
             << "\n";
        cout << "1. Enqueue()"
             << "\n";
        cout << "2. Dequeue()"
             << "\n";
        cout << "3. isEmpty()"
             << "\n";
        cout << "4. Count()"
             << "\n";
        cout << "5  Display()"
             << "\n";
        cout << "6 Clear Screen"
             << "\n";

        Node *n = new Node();

        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enqueue Function Called - "
                 << "\n";
            cout << "Enter the key"
                 << "\n";
            cin >> key;
            cout << "Enter the value"
                 << "\n";
            cin >> value;
            n->key = key;
            n->data = value;
            obj.Enqueue(n);
            break;

        case 2:
            cout << "Dequeue Function Called - "
                 << "\n";
            temp = obj.Dequeue();
            cout << "Dequeue Node: "
                 << "(" << temp->key << ", " << temp->data << ", " << temp->next << ")" << endl;
            break;

        case 3:
            if (obj.isEmpty())
                cout << "Queue is Empty"
                     << "\n";
            else
                cout << "Queue is not Empty"
                     << "\n";
            break;

        case 4:
            cout << "The Total elements in the Queue are " << obj.Count() << "\n";
            break;

        case 5:
            obj.Display();
            break;

        case 6:
            system("clear");
            break;
        default:
            cout << "Invalid Option"
                 << "\n";
            break;
        }
    } while (option != 0);
    return 0;
}
