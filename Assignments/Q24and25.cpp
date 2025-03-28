//When deleting a node z from a BST (in the classic CLRS approach), we often find the successor of z (denoted as y) if z has two children. The successor y is the minimum node in z’s right subtree. Then we perform the following steps:
//Transplant y in place of z only if y is not the direct child of z. If y is not the direct right child of z (i.e., y.parent != z), we:
//Replace y with y.right (so y.right takes y’s place).
//Make z’s right child become y’s right child.
//If y.parent == z, it means the successor is the immediate right child of z. In that case, a simpler step is taken to reconnect pointers since y is already in the position to be transplanted directly.
//So, the test if (y.parent != z) is required to distinguish these two cases and ensure the parent-child pointers are updated correctly.


#include <iostream>   // For standard input/output
using namespace std;
//A Binary Search Tree (BST) is a special kind of binary tree where each node follows these rules:
//Left Subtree Rule: Every node in the left subtree of a node has a value less than the node’s value.
//Right Subtree Rule: Every node in the right subtree of a node has a value greater than the node’s value.
//No Duplicates: Typically, BSTs do not allow duplicate values. If duplicates are allowed, they are usually handled in a consistent way (e.g., always placed on the right).

// Node structure for the BST
struct Node {
    int key;         // The data (key) stored in the node
    Node* left;      // Pointer to the left child
    Node* right;     // Pointer to the right child
    Node* parent;    // Pointer to the parent node

    // Constructor to initialize the node with a given key
    Node(int val) : key(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BST {
private:
    Node* root; // The root of the BST

    // Helper function to perform in-order traversal of the subtree rooted at 'node'
    // In-order traversal visits: left subtree -> node -> right subtree
    void inOrderTraversal(Node* node) {
        if (node == nullptr) {
            return; // Base case: if the node is null, do nothing
        }
        inOrderTraversal(node->left);           // Recursively traverse the left subtree
        cout << node->key << " ";              // Print the key of the current node
        inOrderTraversal(node->right);          // Recursively traverse the right subtree
    }

    // Helper function to search for a key in the subtree rooted at 'node'
    Node* search(Node* node, int key) {
        if (node == nullptr || node->key == key) {
            // If node is null or we found the key, return 'node'
            return node;
        }
        if (key < node->key) {
            // If the key is smaller, search in the left subtree
            return search(node->left, key);
        } else {
            // Otherwise, search in the right subtree
            return search(node->right, key);
        }
    }

    // Transplant function from CLRS
    // Replaces the subtree rooted at 'u' with the subtree rooted at 'v'
    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) {
            // If 'u' is the root, make 'v' the new root
            root = v;
        } else if (u == u->parent->left) {
            // If 'u' is the left child, update the parent's left pointer
            u->parent->left = v;
        } else {
            // Otherwise, update the parent's right pointer
            u->parent->right = v;
        }
        if (v != nullptr) {
            // Update the parent pointer of 'v'
            v->parent = u->parent;
        }
    }

    // Helper function to find the minimum node in a subtree (used to find the successor)
    Node* minimum(Node* node) {
        // The minimum is found by going as far left as possible
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    // Constructor to initialize an empty BST
    BST() : root(nullptr) {}

    // Public function to access the root (for demonstration/testing)
    Node* getRoot() {
        return root;
    }

    // Insert a new key into the BST
    void insert(int key) {
        // Create a new node with the given key
        Node* newNode = new Node(key);

        Node* y = nullptr;    // 'y' will track the parent of the insertion point
        Node* x = root;       // Start from the root and search for the correct insertion point

        // Traverse the tree to find where to insert the new node
        while (x != nullptr) {
            y = x;                        // 'y' is updated to the current node before we go down
            if (newNode->key < x->key) {
                x = x->left;             // Go to the left subtree if the key is smaller
            } else {
                x = x->right;            // Otherwise, go to the right subtree
            }
        }

        // Now, 'y' is the parent where the new node should be inserted
        newNode->parent = y;  // Set the parent pointer of the new node
        if (y == nullptr) {
            // If 'y' is still null, the tree was empty, so newNode is the root
            root = newNode;
        } else if (newNode->key < y->key) {
            // If the new key is smaller, insert as the left child
            y->left = newNode;
        } else {
            // Otherwise, insert as the right child
            y->right = newNode;
        }
    }

    // Delete a node from the BST given a pointer to that node
    void deleteNode(Node* z) {
        if (z == nullptr) {
            return; // If the node is null, nothing to delete
        }

        // CASE 1: If z has no left child, replace z with z->right
        if (z->left == nullptr) {
            transplant(z, z->right);
        }
        // CASE 2: If z has no right child, replace z with z->left
        else if (z->right == nullptr) {
            transplant(z, z->left);
        }
        // CASE 3: z has both left and right children
        else {
            // Find the successor (minimum of right subtree)
            Node* y = minimum(z->right);

            // If the successor is not the direct child of z (y.parent != z),
            // we first transplant y with y->right
            if (y->parent != z) {
                // Transplant y with y->right (this removes y from its current location)
                transplant(y, y->right);
                // Now, set y->right to z->right, and update y->right->parent
                y->right = z->right;
                y->right->parent = y;
            }
            // Transplant z with y
            transplant(z, y);
            // Finally, set y->left to z->left and update the parent
            y->left = z->left;
            y->left->parent = y;
        }

        // Free the memory of the deleted node (optional or done by destructor in real usage)
        delete z;
    }

    // Public function to delete a key (convenience wrapper around deleteNode)
    void deleteKey(int key) {
        // First search for the node with the given key
        Node* z = search(root, key);
        // If found, call deleteNode
        if (z != nullptr) {
            deleteNode(z);
        }
    }

    // Public function to perform in-order traversal of the entire BST
    void inOrder() {
        inOrderTraversal(root);  // Call the helper function on the root
        cout << endl;            // Print a newline after traversal
    }

    // Public function to search a key and return true if found, false otherwise
    bool searchKey(int key) {
        return (search(root, key) != nullptr);
    }
};

int main() {
    BST tree;            // Create a BST object

    // Insert some values
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal after inserts: ";
    tree.inOrder();      // Should print the keys in ascending order

    // Search for a key
    int keyToFind = 40;
    if (tree.searchKey(keyToFind)) {
        cout << keyToFind << " found in the BST.\n";
    } else {
        cout << keyToFind << " not found in the BST.\n";
    }

    // Delete a key
    tree.deleteKey(50);  // Delete the root for demonstration

    cout << "In-order traversal after deleting 50: ";
    tree.inOrder();

    return 0; // End of the program
}
