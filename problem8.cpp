#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertAtEnd(int value, Node *&head)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = nullptr;

    // list is empty
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        // Traverse to the end of the list
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

Node *MergeLinkedList(Node *head1, Node *head2)
{
    Node *dummyNode = (Node *)malloc(sizeof(Node));
    Node *temp = dummyNode;

    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data < head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else if (head1->data > head2->data)
        {
            temp->next = head2;
            head2 = head2->next;
        }
        else
        {
            temp->next = head1;8o0
            head1 = head1->next;

            temp = temp->next;
            temp->next=head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    // the remaining nodes
    if (head1 != nullptr)
        temp->next = head1;
    if (head2 != nullptr)
        temp->next = head2;

    return dummyNode->next; // Return merged list
}

void Display(Node *head)
{
    cout << "----------------------" << endl;
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    cout << "----------------------" << endl;
}

int main()
{
    Node *head1 = nullptr;
    Node *head2 = nullptr;

    int n;
    cout << "Enter the number of elements you want to add to the linked list: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int value;
        cout << "Enter data for First LL node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(value, head1);
    }
    cout << "LL1:" << endl;
    Display(head1);

    int m;
    cout << "Enter the number of elements you want to add to the linked list: ";
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int value;
        cout << "Enter data for second LL node " << i + 1 << " : ";
        cin >> value;
        insertAtEnd(value, head2);
    }
    cout << "LL2:" << endl;
    Display(head2);
    Node *head = MergeLinkedList(head1, head2);
    Display(head);

    return 0;
}