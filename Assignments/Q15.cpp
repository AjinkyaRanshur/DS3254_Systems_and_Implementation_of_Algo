
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

class Stack_LL{

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


int main(){
    Stack<int> s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Size of the stack: " << s.size() << endl;
    cout << "Top element: " << s.topelem() << endl;

    cout << "Popped: " << s.pop() << endl;
    cout << "Size after pop: " << s.size() << endl;

    return 0;
}

