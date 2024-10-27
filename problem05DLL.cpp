// doublyLinkedList
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node * next;
    Node * back;
};

Node * head = nullptr;

void traverseList() {
    cout << "---------------------------------" << endl;
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    Node * temp = head;
    cout << "The doubly linked list is: ";
    while (temp -> next != nullptr) {
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
    newNode -> back = nullptr;

    if (head == nullptr) {
        head = newNode;
        head -> next = nullptr;
    } else {
        newNode -> next = head;
        head -> back = newNode;
        head = newNode;
    }
    cout << "Updated LinkedList :" << endl;
    traverseList();
    return;
}

void insertAtEnd(int value) {
    Node * newNode = (Node * ) malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = nullptr;

    if (head == nullptr) {
        head = newNode;
        head -> back = nullptr;
        return;
    }

    Node * temp = head;
    while (temp -> next != nullptr) {
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> back = temp;
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
        newNode -> next = nullptr;
        newNode -> back = nullptr;
        head = newNode;
        cout << "list is empty so cannot add after a node .so we are inserting at begining" << endl;
    } else {
        Node * temp = head;
        bool found = false;

        while (temp != nullptr) {
            if (temp -> data == givenNode) {
                newNode -> next = temp -> next;
                newNode -> back = temp;
                if (temp -> next != nullptr) {
                    temp -> next -> back = newNode;
                }
                temp -> next = newNode;
                found = true;
                break;
            }

            temp = temp -> next;
        }
        if (!found) {
            cout << "Node with value " << givenNode << " not found." << endl;
            return;
        }
    }

    cout << "Updated LinkedList :" << endl;
    traverseList();
    return;
}

void deleteAtBeginning() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head -> next == nullptr) {
        free(head);
        head = nullptr;
        cout << "Node deleted. List is now empty." << endl;
    } else {
        Node * temp = head;
        head = head -> next;
        free(temp);
        head -> back = nullptr;
    }
    cout << "Updated LinkedList :" << endl;
    traverseList();
    return;
}

void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node * temp = head;
    while (temp -> next != nullptr) {
        temp = temp -> next;
    }
    if (temp == head) {
        free(temp);
        head = nullptr;
        cout << "Node deleted. List is now empty." << endl;
        return;
    }

    temp -> back -> next = nullptr;
    free(temp);

    cout << "Updated LinkedList :" << endl;
    traverseList();
}

void deleteTheGivenNode() {
    int givenNode;
    cout << "give the value of node you want to delete" << endl;
    cin >> givenNode;

    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node * temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp -> data == givenNode) {
            if (temp == head) {
                head = temp -> next;
                if (head != nullptr) {
                    head -> back = nullptr;
                }
                free(temp);
                found = true;
                break;
            } //Node is in the middle or end
            else {
                temp -> back -> next = temp -> next;
                if (temp -> next != nullptr) {
                    temp -> next -> back = temp -> back;
                }
                free(temp);
                found = true;
                break;
            }
        }
        temp = temp -> next;
    }
    if (!found) {
        cout << "Node with value " << givenNode << " not found." << endl;
        return;
    }

    cout << "Updated LinkedList :" << endl;
    traverseList();
}

int main() {
    bool Continue = true;
    int n;
    cout << "Enter the number of elements you want to add to the doubly linked list: ";
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