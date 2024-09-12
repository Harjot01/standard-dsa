// Don't Overthink, Just Code
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        prev = NULL;
        next = NULL;
    }

    Node(int key, int data)
    {
        this->key = key;
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }
    DoublyLinkedList(Node *n)
    {
        head = n;
    }

    Node *NodeExists(int key)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == key)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    void AppendNode(Node *n)
    {
        if (head == NULL)
        {
            head = n;
            cout << "Node Appended" << endl;
        }
        else
        {
            if (NodeExists(n->key) != NULL)
            {
                cout << "Node already exists with the key value of " << n->key << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->prev = ptr;
                cout << "Node Appended" << endl;
            }
        }
    }

    void PrependNode(Node *n)
    {
        if (head == NULL)
        {
            head = n;
            cout << "Node Prepended" << endl;
        }
        else
        {
            if (NodeExists(n->key) != NULL)
            {
                cout << "Node already exists with the key value of " << n->key << endl;
            }

            else
            {
                n->next = head;
                head->prev = n;
                head = n;
                cout << "Node Prepended" << endl;
            }
        }
    }

    void InsertNodeAfter(Node *n, int key)
    {
        Node *ptr;
        ptr = NodeExists(key);
        if (ptr == NULL)
        {
            cout << "No node found with the key value of " << key << endl;
        }
        else
        {
            if (NodeExists(n->key) != NULL)
            {
                cout << "Node already exists with the key value of " << n->key << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next->prev = n;
                ptr->next = n;
                n->prev = ptr;
                cout << "Node Inserted" << endl;
            }
        }
    }

    void InsertNodeBefore(Node *n, int key)
    {
        Node *ptr;
        ptr = NodeExists(key);
        if (ptr == NULL)
        {
            cout << "No node exists with the key value of " << key << endl;
        }
        else
        {
            if (NodeExists(n->key) != NULL)
            {
                cout << "Node already exists with the key value of " << n->key << endl;
            }
            else
            {
                n->prev = ptr->prev;
                ptr->prev->next = n;
                ptr->prev = n;
                n->next = ptr;
                cout << "Node Inserted" << endl;
            }
        }
    }

    void DeleteNodeByKey(int key)
    {
        Node *ptr;
        ptr = NodeExists(key);
        if (ptr == NULL)
        {
            cout << "No node exists with the key value of " << key << endl;
        }
        else
        {
            if (head == NULL)
            {
                cout << "No Nodes in the linked list" << endl;
            }
            else
            {

                if (head->key == key)
                {
                    Node *temp = head->next;
                    delete head;
                    head = temp;
                    cout << "Node Deleted" << endl;
                }
                else
                {
                    if (ptr->next == NULL)
                    {
                        Node *temp = ptr;
                        temp->prev->next = NULL;
                        cout << "Node Deleted" << endl;
                        delete ptr;
                    }
                    else
                    {
                        Node *temp = ptr;
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        delete ptr;
                        cout << "Node Deleted" << endl;
                    }
                }
            }
        }
    }

    void SelectionSort()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *min = temp;
            Node *next = min->next;
            while (next != NULL)
            {
                if (next->data < min->data)
                    min = next;
                next = next->next;
            }
            int data = temp->data;
            temp->data = min->data;
            min->data = data;
            temp = temp->next;
        }
    }

    void UpdateNodeByKey(int key, int data)
    {
        Node *ptr = NodeExists(key);
        if (ptr == NULL)
        {
            cout << "No node exists with the key value of " << key << endl;
        }
        else
        {
            ptr->data = data;
            cout << "Node Updated" << endl;
        }
    }

    void PrintList()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << "(" << ptr->prev << ", " << ptr->key << ", " << ptr->data << ", " << ptr->next << ") <--> ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
};

int main()
{
    DoublyLinkedList s;
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
            s.AppendNode(n1); // we are direcly passing n1 pointer
            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to the Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.PrependNode(n1); // we are direcly passing n1 pointer
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this new node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.InsertNodeAfter(n1, k1);
            break;
        case 4:
            cout << "Insert Node Before Operation \nEnter key of existing Node after which you want to Insert this new node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.InsertNodeBefore(n1, k1);
            break;

        case 5:
            cout << "Delete Node Operation \nEnter key of the Node to the deleted" << endl;
            cin >> k1;
            s.DeleteNodeByKey(k1);
            break;

        case 6:
            cout << "Update Node By Key Operation \nEnter key & new data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            s.UpdateNodeByKey(key1, data1);
            break;

        case 7:
            cout << "Sorting the List" << endl;
            s.SelectionSort();
            break;

        case 8:
            s.PrintList();
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