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

template <typename T>
class qfromstacks{

private:
	Stack<T> s1,s2;

public:

    qfromstacks(int size) :	s1(size),s2(size) {}
	
    void enqueue(T x) {
        s1.push(x);
    }

    T dequeue() {
        if (s2.is_empty()) {
            while (!s1.is_empty()) {
                s2.push(s1.pop());
            }
        }
        if (!s2.is_empty()) {
            return s2.pop();
        } else {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }

    T front() {
        if (s2.is_empty()) {
            while (!s1.is_empty()) {
                s2.push(s1.pop());
            }
        }
        if (!s2.is_empty()) {
            return s2.topelem();
        } else {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }

    int size() {
        return s1.size() + s2.size();
    }



};


int main() {

qfromstacks<int> q(5);


q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.enqueue(40);

cout << "Front Element: " << q.front() << endl;
cout << "Dequeued: " << q.dequeue() << endl;
cout << "Dequeued: " << q.dequeue() << endl;

q.enqueue(50);

cout << "Front Element: " << q.front() << endl;
cout << "Queue Size: " << q.size() << endl;

}


