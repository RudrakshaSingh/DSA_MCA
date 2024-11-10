#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

int height(Node *node)
{
    return (node == nullptr) ? 0 : node->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *createNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

// Right rotate a subtree rooted with y
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

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
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

int getBalance(Node *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node *insert(Node *node, int key)
{
    // Perform the normal BST insertion
    if (node == nullptr)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys are not allowed in the AVL tree
        return node;

    // Update the height of ancestor node and insertion
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
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to delete a node from the AVL tree
Node *deleteNode(Node *root, int key)
{
    // Perform standard BST delete
    if (!root)
        return NULL;

    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // 0 child leaf node
        if (!root->left && !root->right)
        {
            free(root);
            return NULL;
        }
        else if (root->left && !root->right) // left child
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else if (!root->left && root->right)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else
        { // both child exist
            Node *curr = root->right;
            while (curr->left)
            {
                curr = curr->left;
            }

            root->key = curr->key;
            root->right = deleteNode(root->right, curr->key);
        }
    }

    // If the tree had only one node then return
    if (root == nullptr)
        return root;

    // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor of this node to check whether this node became unbalanced
    int balance = getBalance(root);

    if (balance > 1)
    {
        // Left Left Case
        if (getBalance(root->left) >= 0)
        {
            return rightRotate(root);
        }
        else // Left Right Case
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    else if (balance < -1)
    {
        // Right Right Case
        if (getBalance(root->right) <= 0)
        {
            return leftRotate(root);
        }
        else // Right Left Case
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Function to print Inorder traversal
void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Function to print Preorder traversal
void preOrder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to print Postorder traversal
void postOrder(Node *root)
{
    if (root != nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

Node* search(Node* root, int data) {
    if (root == nullptr || root->key == data) {
        return root;
    }
    if (data < root->key) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Main function with menu-driven options
int main()
{
    Node *root = nullptr;
    int choice, value, data;

    // Insert initial elements into the AVL tree
    cout << "Enter elements to insert in the tree (enter -1 to stop): ";
    cin >> data;
    while (data != -1)
    {
        root = insert(root, data);
        cin >> data;
    }

    // Menu-driven loop
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Inorder Traversal\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Insert a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search" << endl;
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
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
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value) == nullptr) {
                cout << "Value not found." << endl;
            } else {
                cout << "Value found." << endl;
            }
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
