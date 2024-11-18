// circularSingleLinkedList
#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node * next;
};
Node * head = nullptr;
void traverseList() {
    cout << "---------------------------------" << endl;
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    Node * temp = head;
    cout << "The circular singly linked list is: ";
    while (temp -> next != head) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << temp -> data << endl;
    cout << endl;
    cout << "---------------------------------" << endl;
}
void insertAtBeginning() {
    int value;
    cout << "Enter value to enter : ";
    cin >> value;
    cout << endl;
    Node * newNode = (Node * ) malloc(sizeof(Node));
    newNode -> data = value;
    if (head == nullptr) {
        head = newNode;
        head -> next = head;
        cout << "Updated LinkedList :" << endl;
        traverseList();
        return;
    }
    newNode -> next = head;
    Node * temp = head;
    while (temp -> next != head) {
        temp = temp -> next;
    }
    temp -> next = newNode;
    head = newNode;
    cout << "Updated LinkedList :" << endl;
    traverseList();
    return;
}
void insertAtEnd(int value) {
    Node * newNode = (Node * ) malloc(sizeof(Node));
    newNode -> data = value;
    if (head == nullptr) {
        head = newNode;
        head -> next = head;
        return;
    }
    Node * temp = head;
    while (temp -> next != head) {
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> next = head;
    return;
}
void insertAfterGivenNode() {
    int value, givenNode;
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Enter the value of the node after which to insert: ";
    cin >> givenNode;
    cout << endl;
    Node * newNode = (Node * ) malloc(sizeof(Node));
    newNode -> data = value;
    if (head == nullptr) {
        newNode -> next = newNode;
        head = newNode;
        cout << "list is empty so cannot add after a node .so we are inserting at begining" << endl;
    } else {
        Node * temp = head;
        while (true) {
            if (temp -> data == givenNode) {
                newNode -> next = temp -> next;
                temp -> next = newNode;
                break;
            }
            temp = temp -> next;
            if (temp == head) {
                cout << "cannot find the given node" << endl;
                break;
            }
        }
    }
    traverseList();
}
void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete.\n" <<
            endl;
        return;
    }
    if (head -> next == head) {
        free(head);
        head = NULL;
        cout << "Node deleted. List is now empty." << endl;
        return;
    }
    Node * temp = head;
    Node * last = head;
    while (last -> next != head) {
        last = last -> next;
    }
    last -> next = head -> next;
    head = head -> next;
    free(temp);
    traverseList();
}
void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head -> next == head) {
        free(head);
        head = NULL;
        cout << "Node deleted. List is now empty." << endl;
        return;
    }
    Node * sLast = head;
    while (sLast -> next -> next != head) {
        sLast = sLast -> next;
    }
    Node * last = sLast -> next;
    sLast -> next = head;
    free(last);
    traverseList();
}
void deleteTheGivenNode() {
    int givenNode;
    cout << "give the value of node you want to delete" << endl;
    cin >> givenNode;
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head -> next == head) {
        if (head -> data == givenNode) {
            free(head);
            head = NULL;
            cout << "Element deleted. List is now empty." << endl;
        } else {
            cout << "Node with value " << givenNode << " not found." << endl;
        }
        traverseList();
        return;
    }
    Node * temp = head;
    Node * prev = nullptr;
    while (true) {
        if (temp -> data == givenNode) {
            if (prev == NULL) { // Deleting the head node
                Node * last = head;
                while (last -> next != head) {
                    last = last -> next;
                }
                head = head -> next;
                last -> next = head;
            } else {
                prev -> next = temp -> next;
            }
            free(temp);
            cout << "Node deleted." << endl;
            traverseList();
            return;
        }
        // Move to the next node
        prev = temp;
        temp = temp -> next;
        // If we've looped back to the head, the node wasn't found
        if (temp == head) {
            cout << "Node with value " << givenNode << " not found." << endl;
            break;
        }
    }
}
int main() {
    bool Continue = true;
    int n;
    cout << "Enter the number of elements you want to add to the circular singly linked list: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(value);
    }
    traverseList();
    while (Continue) {
        char Char;
        cout << "Do you want to continue (y/n)" << endl;
        cin >> Char;
        if (Char != 'y' && Char != 'Y') {
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
        switch (choice) {
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