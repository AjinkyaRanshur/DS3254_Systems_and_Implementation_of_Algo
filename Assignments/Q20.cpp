#include <iostream>
using namespace std;

//Heap is tree based datastructure that follows the heap property.Which is the max or min heap:where the value(x) < or > value(parent(x))
//
//Q1.What are the minimum and maximum number of elements in a heap of height h?
//Answer-> Min=2^h and Max=2^(h+1) -1.The reason is simple the number of nodes follow this formula $\sum_{i=1}^{n} 2^i$ and thus the min it can have is n=h-1 + 1 meaning the last layer has only 1 node in it or the last layer has all the nodes in it which is given by n=h.Let's take an example to highlight this point let us assume h=2 there since the last layer has only node in the min case the number of nbodes will be 2^0+2^1+1=4 and we can call it max when the last layer is full which is given by 2^0+2^1+2^2=7.
//Q2.Show that an n element heap has height [log n]
//Answer-> 
//Q3.Where in a max heap might the smallest element reside assuming all elements are distinct?
//Q4.Is a sorted array a min-heap?
//Q5.Is array 23,17,14,6,13,10,15,7,12 a max heap?
//Q6.Show that with the array representation for storing an n-element heap,the leaves are the nodes indexed by 

class MaxHeap{

//MaxHeapify= Used to make sure that satisfies the property of a heap

private:
	int* arr;
	int capacity;
	int size;

public:

	MaxHeap(int cap){
		capacity=cap;
		size=0;
		arr=new int[capacity];
		for(int i=0;i<capacity;i++){
			arr[i]=0;
		}
	}
	
	void display(){
		for(int i=0;i<capacity;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	void insert(int x){
		arr[size]=x;
		int index=size;
		size++;
		buildheap(arr,size);
	}

	
	int length(){
		return size;
	}
	
	void buildheap(int* array,int n){
		if(n>capacity){
			cout<<"Error Array size exceeds heap capacity"<<endl;
			return;
		}
		size=n;
		
		for(int i=0;i<n;i++){
			arr[i]=array[i];
		}
		for(int i=(size/2)-1;i>=0;i--){
			maxheapify(i);
		}
	}
	
	void maxheapify(int i){
		int left=2*i+1;
		int right=2*i+2;
		int max=i;

	
		if(left < size && arr[max] < arr[left]){
			max=left;
		}
		
		if(right<size && arr[max]<arr[right]){
			max=right;
		}
		
		if(max==i){
			return;
		}
		
		swap(arr[i],arr[max]);
		maxheapify(max);
		
	}
	
	int Max(){

	return arr[0];
	}
	
	int removemax(){
		int temp=arr[0];
		swap(arr[0],arr[size-1]);
		size--;
		maxheapify(0);
		return temp;
	}
		
	void increaseKey(int i,int k){
		if(arr[i] > k){
			cout<<"New value smaller than current value"<<endl;
			return;
		}
		arr[i]=k;
		int index=i;
		while(index>0){
			int parent=(index-1)/2;
			if(arr[parent]<arr[index]){
				swap(arr[parent],arr[index]);
				index=parent;
			}
			else{
			break;
			}
		}
	}


	~MaxHeap(){
		delete[] arr;
	}
 
};

int main(){

	int capacity=7;
	MaxHeap heap(capacity);

	int array[6] = {2, 3, 4, 5, 10, 15};
	heap.buildheap(array,6);
	heap.insert(9);

	int removed_term=heap.removemax();
	cout<<"Removed this term"<< removed_term<<endl;
	heap.display();
	
	return 0;

	
}




