#include <iostream>
using namespace std;

//Binary trees are fundamental data structures in computer science.
//Traversing a binary tree means visiting all the nodes in a specific order.
//Sure! Here's a visual breakdown of the main types of binary tree traversal using a sample tree:
// Binary Tree Traversal Explanations

// Given Binary Tree:
//        1
//       / \
//      2   3
//     / \   \
//    4   5   6

// 1. Inorder Traversal (Left, Root, Right)
//    Order: 4 → 2 → 5 → 1 → 3 → 6
//    Steps:
//    - Visit left subtree (2 → 4, 5)
//    - Visit root (1)
//    - Visit right subtree (3 → 6)
//
//    Traversal Path:
//        L   Root   R
//      (4) → 2 → (5)
//            ↓
//      (4) → 2 → (5) → 1 → (6) → 3

// 2. Preorder Traversal (Root, Left, Right)
//    Order: 1 → 2 → 4 → 5 → 3 → 6
//    Steps:
//    - Visit root (1)
//    - Visit left subtree (2 → 4, 5)
//    - Visit right subtree (3 → 6)
//
//    Traversal Path:
//       Root   L   R
//       1 → (2 → 4 → 5) → (3 → 6)

// 3. Postorder Traversal (Left, Right, Root)
//    Order: 4 → 5 → 2 → 6 → 3 → 1
//    Steps:
//    - Visit left subtree (2 → 4, 5)
//    - Visit right subtree (3 → 6)
//    - Visit root (1)
//
//    Traversal Path:
//       L   R   Root
//      (4 → 5 → 2) → (6 → 3) → 1

// 4. Level Order Traversal (Breadth-First Search)
//    Order: 1 → 2 → 3 → 4 → 5 → 6
//    Steps:
//    - Visit all nodes at depth 0 (1)
//    - Visit all nodes at depth 1 (2, 3)
//    - Visit all nodes at depth 2 (4, 5, 6)
//
//    Traversal Path:
//       1
//       ↓
//      2 → 3
//      ↓   ↓
//     4 → 5 → 6

#include <iostream>
using namespace std;

template <class T>
class BinaryTree {
public:
    // Make Node public so that we can create nodes in main()
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Constructor
    BinaryTree() : root(nullptr) {}

    // Destructor to free memory
    ~BinaryTree() {
        clear(root);
    }

    // Public function to start pre-order traversal
    void preOrderTraversal() {
        preOrderHelper(root);
    }
    
    void inorder(){
	inorder(root);
	}

private:
    // Helper function to free memory recursively
    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    // Helper function for pre-order traversal
    void preOrderHelper(Node* node) {
        if (node == nullptr)
            return;

        // Visit the root node
        cout << node->data << " ";
        // Traverse the left subtree
        preOrderHelper(node->left);
        // Traverse the right subtree
        preOrderHelper(node->right);
    }
	
    void inorder(Node* node){
 	if (node == nullptr) return;	
	inorder(node->left);
	cout<< node->data<<" ";
	inorder(node->right);

	}
	
    void postorder(Node* node){	
	if (node == nullptr) return;
	postorder(node->left);
	postorder(node->right);
	cout<< node->data<<endl;

	}

    


};

int main() {
    // Create the following binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    BinaryTree<int> tree;
    tree.root = new BinaryTree<int>::Node(1);
    tree.root->left = new BinaryTree<int>::Node(2);
    tree.root->right = new BinaryTree<int>::Node(3);
    tree.root->left->left = new BinaryTree<int>::Node(4);
    tree.root->left->right = new BinaryTree<int>::Node(5);

    cout << "Pre-Order Traversal: ";
    tree.inorder();
    //tree.preOrderTraversal();
    cout << endl;

    return 0;
}
























