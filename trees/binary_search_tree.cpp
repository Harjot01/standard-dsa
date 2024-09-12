// Don't Overthink, Just Code
#include <bits/stdc++.h>
#define SPACE 10
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    int data;
    TreeNode *right;

    TreeNode()
    {
        left = NULL;
        data = 0;
        right = NULL;
    }

    TreeNode(int data)
    {
        left = NULL;
        this->data = data;
        right = NULL;
    }
};

class BST
{
public:
    TreeNode *root;

    BST()
    {
        root = NULL;
    }

    BST(TreeNode *n)
    {
        root = n;
    }

    bool isEmpty()
    {
        if (root == NULL)
            return true;
        else
            return false;
    }

    // Inserting a new node
    void InsertNode(TreeNode *n)
    {
        if (root == NULL)
        {
            root = n;
            cout << "Node Inserted" << endl;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                // handling duplicates
                if (n->data == temp->data)
                    return;
                else if ((n->data < temp->data) && (temp->left == NULL))
                {
                    temp->left = n;
                    cout << "Node Inserted" << endl;
                    break;
                }
                else if (n->data < temp->data)
                {
                    temp = temp->left;
                }
                else if ((n->data > temp->data) && (temp->right == NULL))
                {
                    temp->right = n;
                    cout << "Node Inserted" << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    // Printing on the consolve in 2D
    void Print2D(TreeNode *r, int space)
    {
        if (r == NULL)
            return;
        space += SPACE;
        Print2D(r->right, space);
        cout << endl;
        for (int i = SPACE; i < space; ++i)
            cout << " ";
        cout << r->data << endl;
        Print2D(r->left, space);
    }

    // Depth First Search

    // PreOrder traversal
    void PrintPreOrder(TreeNode *r)
    {
        if (r == NULL)
            return;
        else
        {
            cout << r->data << " ";
            PrintPreOrder(r->left);
            PrintPreOrder(r->right);
        }
    }

    // InOrder traversal
    void PrintInOrder(TreeNode *r)
    {
        if (r == NULL)
            return;
        else
        {
            PrintInOrder(r->left);
            cout << r->data << " ";
            PrintInOrder(r->right);
        }
    }

    // PostOrder traversal
    void PrintPostOrder(TreeNode *r)
    {
        if (r == NULL)
            return;
        else
        {
            PrintPostOrder(r->left);
            PrintPostOrder(r->right);
            cout << r->data << " ";
        }
    }

    // Searching a value in BST
    TreeNode *IterativeSearch(int value)
    {
        if (root == NULL)
            return root;
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (temp->data == value)
                    return temp;

                else if (value < temp->data)
                    temp = temp->left;

                else
                    temp = temp->right;
            }
        }
        return NULL;
    }

    // Finding the height of BST
    int height(TreeNode *r)
    {
        if (r == NULL)
            return -1;
        else
        {
            int lheight = height(r->left);
            int rheight = height(r->right);

            if (lheight > rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
        }
    }

    // Breadth First Search
    void PrintLevelOrderBFS(TreeNode *r)
    {
        int h = height(r);
        for (int i = 0; i <= h; ++i)
        {
            PrintGivenLevel(r, i);
        }
    }
    void PrintGivenLevel(TreeNode *r, int level)
    {
        if (r == NULL)
            return;
        else if (level == 0)
            cout << r->data << " ";
        else
        {
            PrintGivenLevel(r->left, level - 1);
            PrintGivenLevel(r->right, level - 1);
        }
    }

    // Deleting a node

    TreeNode *minValueNode(TreeNode *r)
    {
        TreeNode *current = r;
        while (current->left != NULL)
            current = current->left;

        return current;
    }
    TreeNode *DeleteNode(TreeNode *r, int key)
    {
        if (r == NULL)
            return NULL;
        else if (key < r->data)
            r->left = DeleteNode(r->left, key);
        else if (key > r->data)
            r->right = DeleteNode(r->right, key);
        else
        {
            if (r->left == NULL)
            {
                TreeNode *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                TreeNode *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                TreeNode *temp = minValueNode(r->right);
                r->data = temp->data;
                r->right = DeleteNode(r->right, temp->data);
            }
        }
        return r;
    }

        
};

int main()
{
    BST obj;
    int option, data;

    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal BST values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        TreeNode *new_node = new TreeNode();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
            cin >> data;
            new_node->data = data;
            obj.InsertNode(new_node);
            cout << endl;
            break;
        case 2:
            cout << "SEARCH" << endl;
            cout << "Enter the value you want to search: ";
            cin >> data;
            new_node = obj.IterativeSearch(data);
            if (new_node != NULL)
            {
                cout << "Value Found" << endl;
            }
            else
            {
                cout << "Value not Found" << endl;
            }
            break;
        case 3:
            cout << "Delete Node" << endl;
            cout << "Enter the value you want to delete" << endl;
            cin >> data;
            obj.DeleteNode(obj.root, data);
            break;
        case 4:
            cout << "PRINTING AND TRAVERSING" << endl;
            obj.Print2D(obj.root, 5);
            cout << "Printing level order BFS" << endl;
            obj.PrintLevelOrderBFS(obj.root);
            cout << endl;

            break;
        case 5:
            cout << "Height of the Tree" << endl;
            cout << obj.height(obj.root) << endl;
            break;
        case 6:
            cout << "CLS SCR" << endl;
            system("cls");
            break;
        default:
            cout << "Enter proper option number" << endl;
            break;
        }
    } while (option != 0);

    return 0;
}
