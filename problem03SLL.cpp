//Singly Linked List
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
    cout << "The linked list is: ";
    while (temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
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
    newNode -> next = head;
    head = newNode;

    cout << "Updated LinkedList :" << endl;
    traverseList();
}

void insertAtEnd(int value) {
    Node * newNode = (Node * ) malloc(sizeof(Node));

    newNode -> data = value;
    newNode -> next = nullptr;

    // list is empty
    if (head == nullptr) {
        head = newNode;
    } else {
        // Traverse to the end of the list
        Node * temp = head;
        while (temp -> next != nullptr) {
            temp = temp -> next;
        }

        temp -> next = newNode;
    }
}

void insertAfterGivenNode() {
    int value, givenNode;
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Enter the value of the node after which to insert: ";
    cin >> givenNode;
    cout << endl;

    // Traverse the list to find the node with the value givenNode
    Node * temp = head;
    while (temp != nullptr && temp -> data != givenNode) {
        temp = temp -> next;
    }

    if (temp != nullptr) {
        Node * newNode = (Node * ) malloc(sizeof(Node));
        newNode -> data = value;
        newNode -> next = temp -> next;
        temp -> next = newNode;

        cout << "Node with value " << value << " has been inserted after node with value " << givenNode << "." << endl;
    } else {
        cout << "Node with value " << givenNode << " not found." << endl;
    }

    traverseList();
}

void deleteAtBeginning() {
    if (head == nullptr) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    Node * temp = head;
    head = head -> next;
    free(temp);
    traverseList();
}

void deleteAtEnd() {
    if (head == nullptr) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    // Check if there is only one node
    if (head -> next == nullptr) {
        free(head);
        head = nullptr;
        cout << "The only node in the list has been deleted." << endl;
        traverseList();
        return;
    }

    Node * temp = head;
    while (temp -> next -> next != nullptr) {
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = nullptr;

    traverseList();
}

void deleteTheGivenNode() {
    int givenNode;
    cout << "Enter value of node to delete: ";
    cin >> givenNode;
    cout << endl;

    if (head == nullptr) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    // node to be deleted is head 
    if (head -> data == givenNode) {
        Node * temp = head;
        head = head -> next;
        free(temp);
        cout << "Node with value " << givenNode << " has been deleted." << endl;
        traverseList();
        return;
    }

    // Traverse the list to find the node to delete
    Node * current = head;
    Node * previous = nullptr;
    while (current != nullptr && current -> data != givenNode) {
        previous = current;
        current = current -> next;
    }

    // If the node was not found
    if (current == nullptr) {
        cout << "Node with value " << givenNode << " not found." << endl;
        return;
    }

    // Node found,  deletion
    previous -> next = current -> next;
    free(current);

    cout << "Node with value " << givenNode << " has been deleted." << endl;
    traverseList();
}

void count() {
    Node * temp = head;
    int count = 0;

    while (temp != nullptr) {
        count++;
        temp = temp -> next;
    }
    cout << "There are " << count << " nodes in the list." << endl;
}

void reverseSingleLL() {
    Node * current = head;
    Node * prev = nullptr;
    Node * next = nullptr;

    while (current != nullptr) {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    traverseList();
}

int main() {
    bool Continue = true;
    int n;
    cout << "Enter the number of elements you want to add to the linked list: ";
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
        cout << "7. Delete the given nodes\n";
        cout << "8. Count number of nodes in LinkedList\n";
        cout << "9. Reverse LinkedList\n";

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
        case 8:
            count();
            break;
        case 9:
            reverseSingleLL();
            break;
        default:
            break;
        }
    }
    return 0;
}