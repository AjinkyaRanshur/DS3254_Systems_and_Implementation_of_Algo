//Q13.)Implement prepend for LinkedList.
//Q14.)Implement remaining functions of sequence ADT for LinkedList.
//Q15.)Write C++ programs for:
//a. Stack ADT using Array/Vector.
//b. Stack ADT using LinkedList.
//c. Queue ADT using LinkedList.

#include <iostream>
using namespace std;
//This allows to store the linked list of any data type T
template <typename T>

//A linked list is a data structure consisting of nodes where each node contains:
//Data:The actual value stored
//Pointer:A reference or pointer to the next node in the sequence.

class LinkedList{

//Define an internal node class
class Node{

public:
	T data;
	Node* next;
	
	//Constructor 
	Node(const T& value): data(value){
	     next=nullptr;
	}
};

Node* head;
Node* tail;

public:
  LinkedList(){head=tail=nullptr;} //Constructor used to ensure that the list starts empty
  
   //Destructor ensures memory is freed
  ~LinkedList(){
	Node* temp;
	while (head){
	      temp=head; //store the current node
	      head=head->next;//move to the next node
	      delete temp;//delete the stored node		 
		}
	}

   //Append at the end (0(1))
   void append(const T& value){
	Node* newNode=new Node(value);
	if(!head){ //If list is empty
	    head=tail=newNode;
	}else{
	    tail -> next=newNode;
	    tail = newNode;
	}

	}
   
    //Prepend at the beginning (0(1))
    void prepend(const T& value){
	Node* newNode=new Node(value);
	if(!head){
	    head=tail=newNode;
	}else{
	   newNode->next=head;
	   head=newNode;
	}
	}
	
    //Remove a specific value(0(n))
    void remove(const T& value){
	if (!head) return;
	
	//If the head node holds the value
	if (head->data==value){
	    Node* temp;
	    temp=head;
	    head=head->next;
	    delete temp;
	    if (!head) tail=nullptr;
	    return;
	}

	//Otherwise, find the node before the target
	Node* temp=head;
	while(temp -> next && temp ->next->data!=value){
	    temp=temp->next;
	}
	
	//If found
	if(temp->next){
	   Node* toDelete=temp->next;
	   temp->next=temp->next->next;
	   if(!temp->next) tail=temp;
	   delete toDelete;
	}
	}

    int length(){
	Node* temp=head;
	int _length=0;
	while(temp){
	    _length++;
	    temp=temp->next;
	}
	return _length;
	}
	
   T removeLast(){
	T value= tail->data;
	remove(value);
	return value;
	}

   T removeFirst(){
	T value=head->data;
	remove(value);
	return value;
	}
   void printlist() const{
	Node* temp=head;
	while(temp){
	      cout << temp->data<<"->";
	      temp=temp->next;
		}
	cout<<"Null"<<endl;
	}
	

};

int main(){
	LinkedList <int> list;
	cout <<"Appending 10,20,30..\n";
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.printlist();

	cout<<"Removing"<<list.removeLast()<<endl;
	list.printlist();
	
	cout<<"Prepend 5"<<endl;
	list.prepend(5);
	list.printlist();

	cout <<"Removing 20"<<endl;
	list.remove(20);
	list.printlist();

	}











