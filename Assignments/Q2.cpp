//2.)Implement Sorting Algorithms. 
//Develop implementations for the following sorting algorithms: Selection Sort, Insertion Sort, and Merge Sort (and/or Quick Sort).

#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#include <cmath>

int getmin(int a[],int i, int j){
    int min;
    min=i;
    for(int k=i+1;k<j;k++){
	if(a[k] < a[min]){
	   min=k;
	}
	}
    return min;

}

void selectionsort(int b[],int j){

    int swap,min;
    for(int k=0;k<j;k++){
	min=getmin(b,k,j);
	swap=b[k];
	b[k]=b[min];
	b[min]=swap;
	}

}

void insertionsort(int b[],int j){
int i,key;
for (int k=0;k<j;k++){
     key=b[k];
     i=k-1;
     while( i >= 0 && b[i] > key ){
	b[i+1]=b[i];
	i--;
	}
     b[i+1]=key;

	}
}

void merge(int b[],int start,int middle,int end){

int n1=middle-start+1;
int n2=end-middle;

int left[n1]={};
int right[n2]={};

for(int i=0;i<n1;i++){
    left[i]=b[start+i];
}

for(int j=0;j<n2;j++){
    right[j]=b[middle+j+1];
}	

int x=0;
int y=0;

for (int k=start;k<=end;k++){

    if(y>=n2 || (x<n1 && left[x] <= right[y])){
	b[k]=left[x];
	x=x+1;
	}
    else{
	b[k]=right[y];
	y=y+1;
	}

}

}

int mergesort(int b[],int start,int end){
    if(start >= end){
	return 0;
	}
    int middle=((start+end)/2);
    mergesort(b,start,middle);
    mergesort(b,middle+1,end);
    merge(b,start,middle,end);
    return 1;

}

int main(){
    int num;
    int count=0;

    ifstream fp("input.txt");
    if (!fp.is_open()){
    cerr << "File Not Found";
    return 1;
    }
    int b[10]={};

    while(fp>>num){
    b[count]=num;
    count++;
    }
    
    cout<<"Unsorted List ";
    for(int i=0;i<count;i++){
	cout << b[i] <<" ";
    }
    cout << endl;

    //selectionsort(b,count);
    //insertionsort(b,count);
    int someval=mergesort(b,0,count-1);

    cout <<"Sorted List ";
    for(int i=0;i<count;i++){
        cout << b[i]<<" ";
    }
    cout << endl;
	

}

