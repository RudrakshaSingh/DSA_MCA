#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
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

// Function to find the minimum value node in a subtree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int data) {
    if (root == nullptr) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

Node* search(Node* root, int data) {
    if (root == nullptr || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;
    int choice, value, data;
    bool Continue = true;

    cout << "Enter elements with space to insert in tree and enter -1 to stop: ";
    cin >> data;
    while (data != -1) {
        root = insert(root, data);
        cin >> data;
    }

    while (Continue) {
        cout << "\nMenu:\n";
        cout << "1. Insert";
        cout << "              2. Delete";
        cout << "              3. Search\n";
        cout << "4. Inorder Traversal";
        cout << "   5. Preorder Traversal";
        cout << "  6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value) != nullptr) {
                    cout << "Value " << value << " found in the tree." << endl;
                } else {
                    cout << "Value " << value << " not found in the tree." << endl;
                }
                break;
            case 4:
                if (root == nullptr) {
                    cout << "Tree is empty." << endl;
                    break;
                }
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 5:
                if (root == nullptr) {
                    cout << "Tree is empty." << endl;
                    break;
                }
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 6:
                if (root == nullptr) {
                    cout << "Tree is empty." << endl;
                    break;
                }
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 7:
                Continue = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
