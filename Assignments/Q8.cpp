//Q8 Implement insert and remove member functions in myArray.

#include <iostream>
using namespace std;

class MyArray{
  private:
     int* _arr; 
     int  _capacity; 
     int  _size;

  public:
   MyArray(int capacity){
	_arr=new int[capacity];
	_capacity=capacity;
	_size=0;
	}
   ~MyArray(){
	delete [] _arr;
	}

    int length(){
	return _size;
	}

    void append(int x){
	_arr[_size]=x;
	_size++;
	}
    int elementAt(int i){
	return _arr[i];
	}
    void replace(int i,int x){
	_arr[i]=x;
	}
    int removeLast(){
	int ret=_arr[_size - 1];
	_size--;
	return ret;
	}
    int remove(int i){
	int ret=_arr[i];
	for(int j=i;j<_size - 1;j++){
	    _arr[j]=_arr[j+1];
	}
	_size--;
	return ret;	
	}
    void insert(int i,int x){
	_size++;
	for(int j=_size-1;j>=i;j--){
	    _arr[j+1]=_arr[j];
	}
	_arr[i]=x;
	}
    
};

int main(){
    MyArray arr(50);
    for(int i=0;i<10;i++){
	arr.append(2*i);
	}
    //int removed_element=arr.remove(4);
    int insert_index=3;
    int replace_value=5;
    arr.insert(insert_index,replace_value);
    int length_array=arr.length();
    //cout<< "Removed Element" << removed_element << endl;
    cout <<"Length of the array" << length_array <<endl;
    //cout << "Replacing element At " << insert_index << " With "<< replace_value << endl;
    for(int i=0;i<length_array;i++){
	cout << arr.elementAt(i) << " ";
	}
    cout << endl;
	}
