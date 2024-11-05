#include <iostream>
#include <cstdlib>
using namespace std;

// Define a node structure for the AVL tree
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to get the height of a node
int height(struct Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;  // New node is initially added at leaf
    return node;
}

// Right rotate a subtree rooted with y
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate a subtree rooted with x
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get balance factor of a node
int getBalance(struct Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a key into the AVL tree
struct Node* insert(struct Node* node, int key) {
    // Perform the normal BST insertion
    if (node == nullptr)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys are not allowed in the AVL tree
        return node;

    // Update the height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor to check whether this node became unbalanced
    int balance = getBalance(node);

    // If the node becomes unbalanced, there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

// Function to find the node with the minimum key value (used in deletion)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // Loop down to find the leftmost leaf
    while (current->left != nullptr)
        current = current->left;

    return current;
}

// Function to delete a node from the AVL tree
struct Node* deleteNode(struct Node* root, int key) {
    // Perform standard BST delete
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            struct Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else  // One child case
                *root = *temp; // Copy the contents of the non-empty child

            free(temp);
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            struct Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == nullptr)
        return root;

    // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor of this node to check whether this node became unbalanced
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to print Inorder traversal
void inorder(struct Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Function to print Preorder traversal
void preOrder(struct Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to print Postorder traversal
void postOrder(struct Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

// Main function with menu-driven options
int main() {
    struct Node* root = nullptr;
    int choice, value, data;

    // Insert initial elements into the AVL tree
    cout << "Enter elements to insert in the tree (enter -1 to stop): ";
    cin >> data;
    while (data != -1) {
        root = insert(root, data);
        cin >> data;
    }

    // Menu-driven loop
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Inorder Traversal\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Insert a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Exit\n";
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
                preOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "Postorder Traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
