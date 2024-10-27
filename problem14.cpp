#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Inorder Traversal using Stack (Left, Root, Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    
    stack<Node*> s;
    Node* current = root;
    
    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;  // Move to left subtree
        }
        
        current = s.top();
        s.pop();
        cout << current->data << " ";  // Print node value
        
        current = current->right;  // Move to right subtree
    }
}

// Preorder Traversal using Stack (Root, Left, Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    
    stack<Node*> s;
    s.push(root);
    
    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        
        cout << current->data << " ";  // Print node value
        
        // Push right child first so that left child is processed first
        if (current->right != nullptr) {
            s.push(current->right);
        }
        if (current->left != nullptr) {
            s.push(current->left);
        }
    }
}

// Postorder Traversal using two Stacks (Left, Right, Root)
void postorder(Node* root) {
    if (root == nullptr) return;
    
    stack<Node*> s1, s2;
    s1.push(root);
    
    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);
        
        // Push left and right children of removed node to the first stack
        if (current->left != nullptr) {
            s1.push(current->left);
        }
        if (current->right != nullptr) {
            s1.push(current->right);
        }
    }
    
    // Print all elements from the second stack
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
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
