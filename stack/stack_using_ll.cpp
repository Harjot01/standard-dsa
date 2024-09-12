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

class Stack
{
public:
    Node *top;

    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }

    bool NodeExists(int key)
    {
        Node *temp = top;
        bool exists = false;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                exists = true;
                break;
            }
            temp = temp->next;
        }
        return exists;
    }

    void Push(Node *n)
    {
        if (top == NULL)
        {
            top = n;
            cout << "Node Pushed Successfully" << endl;
        }

        else if (NodeExists(n->key))
        {
            cout << "Node already exists with the key value of " << n->key << endl;
            cout << "Try entering a different key" << endl;
        }

        else
        {
            Node *temp = top;
            top = n;
            n->next = temp;
            cout << "Node Pushed Successfully" << endl;
        }
    }

    Node *Pop()
    {
        Node *temp = NULL;
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            temp = top;
            top = top->next;
            cout << "Node Deleted" << endl;
        }
        return temp;
    }

    Node *Peek()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return NULL;
        }
        else
        {
            return top;
        }
    }

    int Count()
    {
        int ct(0);
        Node *temp = top;
        while (temp != NULL)
        {
            ct++;
            temp = temp->next;
        }
        return ct;
    }

    void Display()
    {
        cout << "Displaying all the elements inside the stack" << endl;
        Node *temp = top;
        cout << "-------------------------" << endl;

        while (temp != NULL)
        {
            cout << "(" << temp->key << ", " << temp->data << ", " << temp->next << ")" << endl;
            cout << "-------------------------" << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Stack s;
    int option, key, data;

    do
    {
        cout << "What operation do you want to perform?"
             << "Select Option number. Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. peek()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;
        cin >> option;

        Node *new_node = new Node();

        switch (option)
        {
        case 1:
            cout << "Enter key and value of the node to push in the stack" << endl;
            cin >> key >> data;
            new_node->key = key;
            new_node->data = data;
            s.Push(new_node);
            break;

        case 2:
            cout << "Pop Function Called - Poped Value: " << endl;
            new_node = s.Pop();
            cout << "Top of the stack is "
                 << "(" << new_node->key << ", " << new_node->data << ", " << new_node->next << ")";
            delete new_node; // Deleting the Node
            cout << endl;
            break;

        case 3:
            if (s.isEmpty())
                cout << "Stack is Empty" << endl;
            else
                cout << "Stack is not Empty" << endl;
            break;

        case 4:
            cout << "Peek Function Called..." << endl;
            new_node = s.Peek();
            cout << "Top of the stack is "
                 << "(" << new_node->key << ", " << new_node->data << ", " << new_node->next << ")" << endl;
            break;

        case 5:
            cout << "Count Function Called..." << endl;
            cout << "Number of nodes in the stack are: " << s.Count() << endl;
            break;
        case 6:
            cout << "Display Function Called..." << endl;
            s.Display();
            break;

        case 7:
            system("clear");
            break;
        default:
            cout << "Enter proper option number" << endl;
            
        }

    } while (option != 0);

    return 0;
}