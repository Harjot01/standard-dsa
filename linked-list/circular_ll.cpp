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

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class CircularLinkedList
{
public:
    Node *head;

    CircularLinkedList()
    {
        head = NULL;
    }
    CircularLinkedList(Node *n)
    {
        head = n;
        n->next = head;
    }

    Node *NodeExists(int key)
    {
        Node *temp = NULL;
        Node *ptr = head;
        if (ptr == NULL)
        {
            return temp;
        }
        else
        {
            do
            {
                if (ptr->key == key)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } while (ptr != head);
            return temp;
        }
    }

    void AppendNode(Node *n)
    {
        if (head == NULL)
        {
            head = n;
            n->next = head;
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
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }

                ptr->next = n;
                n->next = head;
                cout << "Node Appended" << endl;
            }
        }
    }

    void PrependNode(Node *n)
    {
        if (head == NULL)
        {
            head = n;
            n->next = head;
            cout << "Node prepended" << endl;
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
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head;
                head = n;
                cout << "Node Prepended" << endl;
            }
        }
    }

    void InsertNodeAfter(Node *n, int key)
    {
        Node *ptr = NodeExists(key);
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

                if (ptr->next == head)
                {
                    ptr->next = n;
                    n->next = head;
                    cout << "Node Inserted at the End" << endl;
                }
                else
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    cout << "Node Inserted in Between" << endl;
                }
            }
        }
    }

    void InsertNodeBefore(Node *n, int key)
    {
        Node *ptr = NodeExists(key);
        if (ptr == NULL)
        {
            cout << "No node exists with the key value of " << key << endl;
        }
        else
        {
            if (ptr == head)
            {
                Node *temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = n;
                n->next = head;
                head = n;
                cout << "Node Inserted at the Beginning" << endl;
            }
            else
            {
                Node *prev_ptr = head;
                Node *curr_ptr = prev_ptr->next;

                while (curr_ptr != head)
                {
                    if (curr_ptr->key == key)
                    {
                        break;
                    }
                    prev_ptr = prev_ptr->next;
                    curr_ptr = curr_ptr->next;
                }
                if (NodeExists(n->key) != NULL)
                {
                    cout << "Node already exists with the key value of " << n->key << endl;
                }
                else
                {
                    n->next = prev_ptr->next;
                    prev_ptr->next = n;
                    cout << "Node Inserted in Between" << endl;
                }
            }
        }
    }

    void DeleteNodeByKey(int key)
    {
        if (head == NULL)
        {
            cout << "No nodes in the linked list" << endl;
        }
        else
        {
            if (head->key == key)
            {
                if (head->next == head)
                {
                    head = NULL;
                    cout << "Node Deleted from Beginning" << endl;
                }
                else
                {
                    Node *ptr = head;
                    while (ptr->next != head)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = head->next;
                    head = head->next;
                    cout << "Node Deleted from Beginning" << endl;
                }
            }
            else
            {
                Node *temp = NULL;
                Node *prev_ptr = head;
                Node *curr_ptr = prev_ptr->next;

                while (curr_ptr != head)
                {
                    if (curr_ptr->key == key)
                    {
                        temp = curr_ptr;
                        break;
                    }
                    prev_ptr = prev_ptr->next;
                    curr_ptr = curr_ptr->next;
                }
                if (temp != NULL)
                {
                    prev_ptr->next = temp->next;
                    cout << "Node Deleted" << endl;
                }
                else
                {
                    cout << "No node exists with the key value of " << key << endl;
                }
            }
        }
    }

    void UpdateNodeByKey(int key, int value)
    {
        Node *ptr = NodeExists(key);
        if (ptr != NULL)
        {
            ptr->data = value;
            cout << "Node Updated" << endl;
        }
        else
        {
            cout << "No node exists with the key value of " << key << endl;
        }
    }

    void PrintList()
    {
        Node *ptr = head;
        do
        {
            cout << "(" << ptr->key << ", " << ptr->data << ", " << ptr->next << ") --> ";
            ptr = ptr->next;
        } while (ptr != head);
    }
};

int main()
{

    CircularLinkedList obj;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. insertNodeBefore()" << endl;
        cout << "5. deleteNodeByKey()" << endl;
        cout << "6. updateNodeByKey()" << endl;
        cout << "7. print()" << endl;
        cout << "8. Clear Screen" << endl
             << endl;

        cin >> option;
        Node *n1 = new Node();
        // Node n1;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.AppendNode(n1);
            // cout<<n1.key<<" = "<<n1.data<<endl;
            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.PrependNode(n1);
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            obj.InsertNodeAfter(n1, k1);
            break;

        case 4:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            obj.InsertNodeBefore(n1, k1);
            break;

        case 5:

            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            obj.DeleteNodeByKey(k1);

            break;
        case 6:
            cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            obj.UpdateNodeByKey(key1, data1);

            break;
        case 7:
            obj.PrependNode(n1);

            break;
        case 8:
            system("clear");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}