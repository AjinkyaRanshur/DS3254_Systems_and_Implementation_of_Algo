#include <iostream>
using namespace std;

//Binary trees are fundamental data structures in computer science.
//Traversing a binary tree means visiting all the nodes in a specific order.
//Sure! Here's a visual breakdown of the main types of binary tree traversal using a sample tree:
template <class T>
class BinaryTree{
	private:
	  T _data;
	  Node* _left;
	  Node* _right;
	  
	  Node(const T& value):data(value){
		_left=nullptr;
		_right=nullptr;
	}

	//The node is visited first,followed by its left child and then its right child.This can be visualized as Root-left-Right 
	void preorder(){
	}
	//void inorder(){}
	//void postorder(){}
	
	};

	Node* _root;


