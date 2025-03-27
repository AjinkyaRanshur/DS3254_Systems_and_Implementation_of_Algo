
//Q15.)Write C++ programs for:
//a. Stack ADT using Array/Vector.
//b. Stack ADT using LinkedList.
//c. Queue ADT using LinkedList.

//Q16.)Is it possible to implement a Queue using Stacks?

#include <iostream>
using namespace std;
template <typename T>


class Stack{

private:
	T* arr;
	int top;
	int capacity;
public:
	Stack(T size){
		capacity=size;
		arr= new T[capacity];
		top=0;
	}
	
	~Stack(){
		delete arr;
	}
	
	void push(int x){
		if(top>capacity){
			cout<<"We have unfortunately Reached Maximum Capacity which is called Stack Overflow"<< endl;
			return;
		}
		arr[top]=x;
		top++;	
	}


	T topelem(){
		T last_element=arr[top-1];
		return last_element;
	}
	

	T pop(){
		T popped_element=arr[top-1];
		arr[top-1]=0;
		top--;
		return popped_element;
	}

	int size(){
		return top;
	}

	bool is_full(){
		return top==capacity;
	}

	bool is_empty(){
		return top==0 && arr[top]==0;
	}


};

template <typename T>
class Stack_LL{

private:
	class Node{
	public:
		T data;
		Node* next;
		
		Node(const T& value):data(value){
			next=nullptr;
		}
	};

	Node* head;
	Node* tail;
public:
	Stack_LL(){head=tail=nullptr;}
	
	~Stack_LL(){
		Node* temp;
		while(head){
		      temp=head;
		      head=head->next;
		      delete temp;
		}
	}
	
	void push(const T& value){
		Node* newNode=new Node(value);
		if(!head){
		    head=tail=newNode;
		}else{
		      newNode->next=head;
		      head=newNode;
		}	
	}


	T topelem(){
		T value=head->data;
		return value;
	}

	T pop(){
		Node* temp=head;
		T value=temp->data;
		head=head->next;
		delete temp;
		return value;
	}


	int size(){
		Node* temp=head;
		int _length=0;
		while(temp){
		    _length++;
		    temp=temp->next;
		}
		return _length;
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


template <typename T>
class Queue_LL{

private:
	class Node{
	public:
		T data;
		Node* next;
		
		Node(const T& value):data(value){
			next=nullptr;
		}
	};

	Node* head;
	Node* tail;
public:
	Queue_LL(){head=tail=nullptr;}
	
	~Queue_LL(){
		Node* temp;
		while(head){
		      temp=head;
		      head=head->next;
		      delete temp;
		}
	}
	
	bool is_empty(){
		return head==nullptr;
	}
	
	bool is_full(){
		return false;	
	}
	
	void enqueue(const T& value){
		Node* newNode=new Node(value);
		if(!head){
		    head=tail=newNode;
		}else{
		      tail->next=newNode;
		      tail=newNode;
		}	
	}


	T first(){
		T value=head->data;
		return value;
	}

	T dequeue(){
		if(is_empty()){
			throw underflow_error("Queue underflow");
		}
		else{
		Node* temp=head;
		T value=temp->data;
		head=head->next;
		delete temp;
		return value;
		}
	}


	int size(){
		Node* temp=head;
		int _length=0;
		while(temp){
		    _length++;
		    temp=temp->next;
		}
		return _length;
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
    //Stack<int> s(5);

    //s.push(10);
    //s.push(20);
    //s.push(30);

    //cout << "Size of the stack: " << s.size() << endl;
    //cout << "Top element: " << s.topelem() << endl;

    //cout << "Popped: " << s.pop() << endl;
    //cout << "Size after pop: " << s.size() << endl;

    Queue_LL <int> list;
    list.enqueue(10);
    list.enqueue(20);
    list.enqueue(30);
    list.enqueue(40);

    list.printlist();
    cout <<"Size of the list"<<list.size()<<endl;
    cout <<"Top Element"<<list.first() <<endl;
    cout <<"Dequeued Element" <<list.dequeue()<<endl;
    list.printlist();
    cout<<"Size after Dequeueing"<<list.size()<<endl;

    return 0;
}

