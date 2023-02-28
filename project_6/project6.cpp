#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;       // Value stored in the node
    Node* left;     // Pointer to the left child node
    Node* right;    // Pointer to the right child node
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node(); // Allocate memory for new node
    newNode->data = value;      // Set Node to given value
    newNode->left = nullptr;    // Init left and right child pointers to null
    newNode->right = nullptr;
    return newNode;             // Return the node
}

// Function to insert a node
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {          // If root is null, create new node and set as the root
        root = createNode(value);
    }
    else if (value <= root->data) { // If value is less than or equal to the root value, insert to left subtree
        root->left = insertNode(root->left, value);
    }
    else {                          // If value is greater than the root node's value, insert into the right subtree
        root->right = insertNode(root->right, value);
    }
    return root;                    // Return root of updated tree
}

// Function to find the node with minimum value
Node* findMinNode(Node* root) {
    while (root->left != nullptr) { // Traverse left subtree until min value found
        root = root->left;
    }
    return root;                    // Returns node with min value
}

// Function to remove a node
Node* removeNode(Node* root, int value) {
    if (root == nullptr) {          // If tree is empty, return null
        return root;
    }
    else if (value < root->data) {  // If value is less than the root node's value, remove it from the left subtree
        root->left = removeNode(root->left, value);
    }
    else if (value > root->data) {  // If the value is greater than the root node's value, remove from right subtree
        root->right = removeNode(root->right, value);
    }
    else {                          // If the value is equal to the root node, remove root node
        // Case 1: No child or one child
        if (root->left == nullptr) {  // If root has no left child, replace it with the right
            Node* temp = root->right;
            delete root;              // Deleting the root
            return temp;              // Returning the new root
        }
        else if (root->right == nullptr) {  // If the root has no right child, replace with the left
            Node* temp = root->left;
            delete root;              // Deleting root
            return temp;              // Returning new root
        }
        // Case 2: Two children
        Node* temp = findMinNode(root->right);  // Using findMinNode function to find minimum value in right subtree
        root->data = temp->data;                // Replace root node's value with min value
        root->right = removeNode(root->right, temp->data);  // Remove min node in the right subtree
    }
    return root;
}

// In-order traversal function
void inOrderTraversal(Node* root) {
    if (root == nullptr) {  // If root is null, return
        return;
    }
    inOrderTraversal(root->left); // Recursively traversing the left subtree
    cout << root->data << " ";
    inOrderTraversal(root->right);  // REcoursively traversing the right subtree
}

int main() {
    Node* root = nullptr;

    // Insert nodes into the tree
    root = insertNode(root, 15);
    root = insertNode(root, 5);
    root = insertNode(root, 22);
    root = insertNode(root, 9);
    root = insertNode(root, 30);
    
    // Test removeNode function by removing a node and checking the in-order traversal
    root = removeNode(root, 22);
    cout << "In-order traversal after removing 20: ";
    inOrderTraversal(root);
    cout << endl;

    // Test findMinNode function by finding the minimum value in the tree
    Node* minNode = findMinNode(root);
    cout << "Minimum value in the tree: " << minNode->data << endl;
    
    
    return 0;
}
