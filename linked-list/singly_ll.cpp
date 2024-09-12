// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

// First creating a node in the memory
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
    }
};

// Second linking all the nodes in the memory using pointers and other algorithms
class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }

    SinglyLinkedList(Node *n)
    {
        head = n;
    }

    // To check Whether the key exists or not for a particular node to update, delete or insert
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }


    // Appending a Node
    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with the key value of: " << n->key << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node Appended" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node Appended" << endl;
            }
        }
    }

    // Prepending a Node
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with the key value of: " << n->key << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node Prepended" << endl;
        }
    }

    void insertNodeAfter(Node *n, int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exists with the key value of: " << k << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node already exists with the key value of: " << n->key << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node Inserted" << endl;
            }
        }
    }

    void insertNodeBefore(Node *n, int key)
    {
        Node *ptr = nodeExists(key);
        if (ptr != NULL)
        {
            if (ptr == head)
            {
                n->next = head;
                head = n;
                cout << "Node Inserted at the beginning" << endl;
            }
            else
            {

                Node *prev_ptr = head;
                Node *curr_ptr = prev_ptr->next;
                while (curr_ptr != NULL)
                {
                    if (curr_ptr->key == key)
                    {
                        curr_ptr = NULL;
                    }
                    else
                    {
                        prev_ptr = prev_ptr->next;
                        curr_ptr = curr_ptr->next;
                    }
                }
                if (nodeExists(n->key) != NULL)
                {
                    cout << "Node already exists with the key value of " << n->key << endl;
                }
                else
                {
                    n->next = prev_ptr->next;
                    prev_ptr->next = n;
                    cout << "Node Inserted" << endl;
                }
            }
        }
        else
        {
            cout << "No node exists with the key value of" << key << endl;
        }
    }

    void deleteNodeByKey(int k)
    {
        if (head == NULL)
        {
            cout << "SinglyLinkedList Empty, so cannot delete the items" << endl;
        }
        else if (head != NULL)
        {
            if (head->key == k)
            {
                Node *temp = head->next;
                delete head;
                head = temp;
                cout << "Node Deleted" << endl;
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = prevptr->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        currentptr = currentptr->next;
                        prevptr = prevptr->next;
                    }
                }
                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    delete temp;
                    cout << "Node Deleted" << endl;
                }
                else
                {
                    cout << "Node does not exists with the key value of: " << k << endl;
                }
            }
        }
    }

    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node Data Updated Successfully" << endl;
        }
        else
        {
            cout << "No Nodes exists with the key value of: " << k << endl;
        }
    }

    void selectionSort()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *min = temp;
            Node *next = temp->next;
            while (next != NULL)
            {
                if (next->data < min->data)
                    min = next;
                next = next->next;
            }
            int value = temp->data;
            temp->data = min->data;
            min->data = value;

            temp = temp->next;
        }
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "No Nodes in the Singly Linked List" << endl;
        }
        else
        {
            cout << endl
                 << "Singly Linked List items" << endl;
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ") --> ";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "\nWhat Operation do you want to perform? Select option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. insertNodeBefore()" << endl;
        cout << "5. deleteNodeByKey()" << endl;
        cout << "6. updateNodeByKey()" << endl;
        cout << "7. Sorting the List()" << endl;
        cout << "8. Print()" << endl;
        cout << "9. Clear Screen" << endl
             << endl;

        cin >> option;
        Node *n1 = new Node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to the Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1); // we are direcly passing n1 pointer
            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to the Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1); // we are direcly passing n1 pointer
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this new node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNodeAfter(n1, k1);
            break;
        case 4:
            cout << "Insert Node Before Operation \nEnter key of existing Node after which you want to Insert this new node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNodeBefore(n1, k1);
            break;

        case 5:
            cout << "Delete Node Operation \nEnter key of the Node to the deleted" << endl;
            cin >> k1;
            s.deleteNodeByKey(k1);
            break;

        case 6:
            cout << "Update Node By Key Operation \nEnter key & new data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            s.updateNodeByKey(key1, data1);
            break;

        case 7:
            cout << "Sorting Function Called..." << endl;
            s.selectionSort();
            break;

        case 8:
            s.printList();
            break;

        case 9:
            system("clear");
            break;

        default:
            cout << "Enter Proper Option Number" << endl;
            break;
        }
    } while (option != 0);

    return 0;
}