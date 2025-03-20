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


























