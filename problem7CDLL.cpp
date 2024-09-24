// circulardoublyLinkedList

// linkedlist
#include <bits/stdc++.h>
using namespace std;

// structor of 1d linkedList
struct Node
{
    int data;
    Node *next;
    Node *back;
};

Node *head = nullptr;

void traverseList()
{
    cout << "---------------------------------" << endl;
    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    }

    Node *temp = head;
    cout << "The doubly linked list is: ";
    while (true)
    {
        cout << temp->data << " ";
        temp = temp->next;
        if (temp == head)
        {
            break;
        }
    }

    cout << endl;
    cout << "---------------------------------" << endl;
}

void insertAtBeginning()
{
    int value;
    cout << "Enter value to enter : ";
    cin >> value;
    cout << endl;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (head == nullptr)
    {
        newNode->next = newNode;
        newNode->back=newNode;
        head = newNode;
    }
    else
    {
       newNode->next = head;
       newNode->back=head->back;
       head->back->next=newNode;
       head->back=newNode;

       head = newNode;
    }
    cout << "Updated LinkedList :" << endl;
    traverseList();
    return;
}

void insertAtEnd(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (head == nullptr)
    {
        newNode->back = newNode;
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->back = temp;
        newNode->next = head;
        head->back = newNode;
    }
    return;
}

void insertAfterGivenNode()
{
    int value, givenNode;
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Enter the value of the node after which to insert: ";
    cin >> givenNode;
    cout << endl;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (head == nullptr)
    {
        newNode->next = newNode;
        newNode->back=newNode;
        head = newNode;
        cout << "list is empty so cannot add after a node .so we are inserting at begining" << endl;
    }
    else
    {
        Node *temp = head;
        bool found = false;

        while(true){
            if(temp->data==givenNode){
                newNode->next=temp->next;
                newNode->back=temp;
                temp->next->back=newNode;
                temp->next=newNode;
                found=true;
                break;
            }
            temp=temp->next;
            if(temp==head){
                break;
            }
        }
        if (!found)
        {
            cout << "Node with value " << givenNode << " not found." << endl;
            return;
        }
    }

    cout << "Updated LinkedList :" << endl;
    traverseList();
    return;
}

void deleteAtBeginning()
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head->next == head)
    {
        free(head);
        head = nullptr;
        cout << "Node deleted. List is now empty." << endl;
        return;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        head->back = temp->back;
        temp->back->next = head;
        free(temp);
        
    }
    cout << "Updated LinkedList :" << endl;
    traverseList();
    return;
}

void deleteAtEnd()
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head->next == head)
    {
        free(head);
        head = nullptr;
        cout << "Node deleted. List is now empty." << endl;
        return;
    }else{
        Node *temp = head->back;
        head->back->back->next = head;
        head->back = head->back->back;
        free(temp);
    }
    

    cout << "Updated LinkedList :" << endl;
    traverseList();
}

void deleteTheGivenNode()
{
    int givenNode;
    cout << "give the value of node you want to delete" << endl;
    cin >> givenNode;

    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node *temp = head;
    bool found = false;
    while (true)
    {
        if(temp->data==givenNode){
            if(temp==head){
                found=true;
                deleteAtBeginning();
                return;
            }else{
                temp->back->next=temp->next;
                temp->next->back=temp->back;
                free(temp);
                found=true;
                break;
            }
        }
        temp = temp->next;
        if (temp == head)
        {
            break;
        }
    }
    
    if (!found)
    {
        cout << "Node with value " << givenNode << " not found." << endl;
        return;
    }

    cout << "Updated LinkedList :" << endl;
    traverseList();
}

int main()
{
    bool Continue = true;
    int n;
    cout << "Enter the number of elements you want to add to the circular doubly linked list: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int value;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(value);
    }
    traverseList();

    while (Continue)
    {
        char Char;
        cout << "Do you want to continue (y/n)" << endl;
        cin >> Char;
        if (Char != 'y' && Char != 'Y')
        {
            Continue = false;
            cout << "Exiting program." << endl;
            break;
        }

        cout << "\nMenu:\n";
        cout << "1. Traverse In LinkedList\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at End\n";
        cout << "4. Insert after given node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete the given node\n";

        cout << "Enter your choice: ";

        int choice, value;
        cin >> choice;

        switch (choice)
        {
        case 1:
            traverseList();
            break;
        case 2:
            insertAtBeginning();
            break;
        case 3:
            int value;
            cout << "Enter value to enter : ";
            cin >> value;
            cout << endl;
            insertAtEnd(value);
            traverseList();
            break;
        case 4:
            insertAfterGivenNode();
            break;
        case 5:
            deleteAtBeginning();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            deleteTheGivenNode();
            break;
        default:
            break;
        }
    }

    return 0;
}
