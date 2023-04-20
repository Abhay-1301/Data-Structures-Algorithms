#include <bits/stdc++.h>
using namespace std;

// class for Node for linked list
class Node
{
public:
    int data;
    Node *next;

    // constructor for class Node
    Node(int value)
    {
        data = value;
        next = NULL;
    }

    // default constructor for class node
    Node()
    {
        next = NULL;
    }
};

// New class for linkedList which always has Node* head in it
class linkedList
{
public:
    Node *head;

    // constructor for linkedList class. It initializes head node as NULL and further we can update it as per different functions.
    linkedList()
    {
        head = NULL;
    }

    // function to insert data at the beginning of list
    // Time complexity:  O(1)
    // Space complexity:  O(1)
    void insertAtFront(int value)
    {
        Node *New = new Node(value);
        if (head == NULL)
        {
            head = New;
        }
        else
        {
            New->next = head;
            head = New;
        }
    }

    // function to insert data at any index of list assuming head index is 0
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    void insertAtIndex(int index, int value)
    {

        if (index == 0)
        {
            insertAtFront(value);
            return;
        }

        Node *New = new Node(value);
        Node *ptr = head;
        int i = 0;
        while (i != index - 1)
        {
            ptr = ptr->next;
            i++;
        }
        New->next = ptr->next;
        ptr->next = New;
    }

    // function to insert data at end of list
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    void insertAtEnd(int value)
    {
        Node *New = new Node(value);
        if (head == NULL)
        {
            head = New;
        }
        else
        {
            Node *ptr = head;
            while (ptr != NULL)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = New;
                    return;
                }

                else
                {
                    ptr = ptr->next;
                }
            }
        }
    }

    // function to delete last element of list
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    void deleteAtEnd()
    {
        Node *curr = head;
        Node *Next = head->next;
        while (Next->next != NULL)
        {
            curr = curr->next;
            Next = Next->next;
        }

        curr->next = NULL;
        delete (Next);
    }

    // function to delete first element of list
    // Time complexity:  O(1)
    // Space complexity:  O(1)
    void deleteAtFront()
    {
        Node *ptr = head;
        head = head->next;
        delete (ptr);
    }

    // function to delete element of given value from list
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    void deleteValue(int value)
    {
        Node *curr = head;
        Node *Next = head->next;

        if (curr->data == value)
        {
            head = head->next;
            delete (curr);
        }
        else
        {
            while (Next->data != value && Next->next != NULL)
            {
                curr = curr->next;
                Next = Next->next;
            }

            if (Next->data == value)
            {
                curr->next = Next->next;
                delete (Next);
            }
        }
    }

    // function to delete data at given index of list
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    void deleteAtIndex(int index)
    {

        if (index == 0)
        {
            deleteAtFront();
            return;
        }

        Node *curr = head;
        Node *Next = head->next;
        int i = 0;
        while (i != index - 1)
        {
            curr = curr->next;
            Next = Next->next;
            i++;
        }

        curr->next = Next->next;
        delete (Next);
    }

    // function to reverse the list
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    void reverse()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // function to display/print list
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    void display()
    {
        Node *ptr = head;

        if (ptr == NULL)
        {
            cout << "Empty List" << endl;
        }
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    // function to find if given value is in the list or not
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    Node *search(int value)
    {
        Node *ptr = head;

        if (ptr == NULL)
        {
            // cout << "Empty List" << endl;
            return NULL;
        }

        else
        {
            while (ptr != NULL)
            {
                if (ptr->data == value)
                {
                    // cout << "YES,'" << value << "' is in the list." << endl;
                    return ptr;
                }
                else
                {
                    ptr = ptr->next;
                }
            }
            // cout << "NO,'" << value << "' is not in the list." << endl;
            return NULL;
        }
    }

    // function to know address of head node
    // Time complexity:  O(1)
    // Space complexity:  O(1)
    Node *HEAD()
    {
        if (head == NULL)
        {
            // cout << "Empty List" << endl;
            return NULL;
        }

        else
        {
            return head;
        }
    }
};

int main()

{

    // dynamically allocated memory for my list in heap
    linkedList *list1 = new linkedList();
    linkedList *list2 = new linkedList();

    // taking same input in two lists
    int n;
    cout << "Enter total number of elements : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        list1->insertAtEnd(x);
        list2->insertAtEnd(x);
    }

    // reversing the second list
    list2->reverse();

    // taking address of head of two lists
    Node *ptr1 = list1->HEAD();
    Node *ptr2 = list2->HEAD();

    // checking if the list is palindrome or not
    while (ptr1 != NULL || ptr2 != NULL)
    {
        if (ptr1->data != ptr2->data)
        {
            cout << "False" << endl;
            break;
        }
        else
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    if (ptr1 == NULL && ptr2 == NULL)
    {
        cout << "True" << endl;
    }

    // freeing the dynamically allocated memory
    delete (list1);
    delete (list2);

    // Time complexity:  O(N)
    // Space complexity:  O(N)
    return 0;
}