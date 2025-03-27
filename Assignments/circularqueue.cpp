#include <iostream>
using namespace std;

//In a regular queue once the rear pointer reaches the end of the array you cannot add new elements even if there is free space at the begginings due to earlier removals without shifting the elements.In acircular queue this problem is solved by wrapping around the pointers ensuring that all available slots are in the fixed-size array are used effieciently.


template<class T>
class CircularQueue{

private:
	T *_arr; // Pointer to the dynamically allocated array holding queue elements
	int _front;//Index of the front element in the queue
	int _rear;//Index where the next elements will be inserted 
	int _capacity;//The size of the array(which is the user capacity+1)

public:
	//Constructor: Initialize the circular queue with a given capacity;
	//We add one extra slot so that we can distinguish between full and empty states;
	CircularQueue(int cap){
		_capacity =cap+1;//Allocate an extra slot 
		_arr=new T[_capacity];//Dynamically allocate the array
		_front = _rear = 0;//Intially both front and rear at 0(empty queue)
	}

	~CircularQueue(){
		delete[] _arr;
	}
	
	bool is_empty(){
		return _front == _rear;
	}
	
	//Returns true if the queue is full.
	//When the next position of _rear (with wrapping) equals _front,the queue is full.
	bool is_full(){
		return ((_rear+1)%_capacity == _front); //_capacity == _front;
	}
	
	//Enqueue():Adds an element to the rear of the queue 
	void enqueue(const T& val){
	    if(is_full()){
		cout << "Queue is full" <<endl;
		return;
		}
	
 	    _arr[_rear]=val; //Insert the value at current rear index
	   _rear=(_rear+1)%_capacity;//Move to the next position with wrap-around 

	}
	
	//dequeue():Removes and returns the elements at the front of the queue
	T& dequeue(){
		if(is_empty()){
		   throw std::underflow_error("Queue is empty");
		}
		
		T& ret=_arr[_front];//Store the front element
		_front=(_front+1);//Move front to the next position with wrap-around
		
		return ret;//Return the removed element
	}

	T peek(){
		if(is_empty){
		    throw std::underflow_error("Queue is empty");
		}
		
		return _arr[_front];
	}
	
	int size(){
		if(_rear >= _front){
			return _rear - _front;
		}
		
		else{
			return _capacity - _front + _rear;
		}
	}

	

};


int main(){

	CircularQueue<int> cq(5);//Create a circular queue with capacity for 5 elements
	
	cq.enqueue(10);
	cq.enqueue(20);
	cq.enqueue(30);
	cq.enqueue(40);

	cout <<"Dequeued:"<< cq.dequeue()<<endl;//should print 10

	

return 0;
}




