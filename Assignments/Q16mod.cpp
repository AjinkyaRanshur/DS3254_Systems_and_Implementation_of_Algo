#include <iostream>
using namespace std;

//Q16 Is it possible to implement a Queue using Stacks?
//
//
template <typename T>
class Stack{


private:
	T* arr;
	int top;
	int capacity;
public:
	Stack(T size){
		capacity=size;
		arr=new T[capacity];
		top=0;
	}
	
	~Stack(){
		delete arr;
	}
	
	void push(int x){
		if(top > capacity){
			cout<< "Overflow Reached"<<endl;
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

int main() {

Stack<int> s(5);

s.push(10);
s.push(20);
s.push(30);
s.push(40);


cout <<"Size of the stack"<< s.size()<<endl;
cout <<"Top Element"<<s.topelem() <<endl;

}


