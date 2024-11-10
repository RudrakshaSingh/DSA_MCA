#include <iostream>
#include <cstdlib> // for malloc and free
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Top -> [SecondNode] -> [FirstNode] -> nullptr
struct StackNode {
    Node* treeNode;
    StackNode* next;
};

bool isEmpty(StackNode* top) {
    return top == nullptr;
}

void push(StackNode*& top, Node* node) {
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->treeNode = node;
    newStackNode->next = top;
    top = newStackNode;
}

void pop(StackNode*& top) {
    if (isEmpty(top)) {
        cout << "Stack underflow\n";
        return;
    }
    StackNode* temp = top;
    top = top->next;
    free(temp);  
}

Node* top(StackNode* top) {
    if (isEmpty(top)) {
        return nullptr;
    }
    return top->treeNode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        cout << "Duplicate value " << data << " not inserted." << endl;
        return root;
    }
    return root;
}

// Inorder Traversal using Stack (Left, Root, Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    
    StackNode* stack = nullptr;
    Node* current = root;
    
    while (true)
    {
        if (current != nullptr)
        {
            push(stack, current);
            current = current->left;
        }else{
            if (isEmpty(stack)) break; // no more node to travel
            current = top(stack);
            pop(stack);
            cout << current->data << " ";
            current = current->right;
        }   
    }
}

// Preorder Traversal using Stack (Root, Left, Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    
    StackNode* stack = nullptr;
    push(stack, root);
    
    while (!isEmpty(stack)) {
        Node* current = top(stack);
        pop(stack);
        
        cout << current->data << " ";  // Print value
        
        // Push right child first so that left child is processed first
        if (current->right != nullptr) {
            push(stack, current->right);
        }
        if (current->left != nullptr) {
            push(stack, current->left);
        }
    }
}

// Postorder Traversal using two Custom Stacks (Left, Right, Root)
void postorder(Node* root) {
    if (root == nullptr) return;
    
    StackNode* s1 = nullptr;
    StackNode* s2 = nullptr;
    
    push(s1, root);
    
    while (!isEmpty(s1)) {
        Node* current = top(s1);
        pop(s1);
        push(s2, current);//put from first stack to second and put child in 1 stack
        
        if (current->left != nullptr) {
            push(s1, current->left);
        }
        if (current->right != nullptr) {
            push(s1, current->right);
        }
    }
    
    // Print all elements from the second stack
    while (!isEmpty(s2)) {
        cout << top(s2)->data << " ";
        pop(s2);
    }
}

int main() {
    Node* root = nullptr;
    int choice, value, data;

    cout << "Enter elements with space to insert in tree and enter -1 to stop: ";
    cin >> data;
    while (data != -1) {
        root = insert(root, data);
        cin >> data;
    }

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Inorder Traversal";
        cout << "   2. Preorder Traversal";
        cout << "   3. Postorder Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 2:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
