//1. Write a Selection Sort function.
//(a) Revise your program to read input from the keyboard.
//(b) Revise your program to read input from a file (the file name should be taken as
//              an argument from the command line).

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//int main() {

//   const int MAX_SIZE=100;
//   char input[MAX_SIZE];
   
//   cout <<"Who are you?";

//   cin.getline(input,MAX_SIZE);
	//read at most MAX_SIZE or till '\n'
	
//   cout << "Hello " << input << endl;

//   return 0;

int getmin(int a[],int i,int j){
	int min=i;
	for(int k=i+1;k<=j;k++){
	   if (a[k]<a[min]){
		min=k;
	}

	}
	return min;
}

int main(){

   //It will open the input.txt file and then link it to the variable fp for reading
   ifstream fp("input.txt");
   
   if (!fp.is_open()) {//check if the fil is opened
     cerr<< "Error Opening the file";
     return 1;
}

//Used to store the numbers read from the file and count is used to keep track of the total number of values read
int num;
int count=0;
int x[10]={};
int min;
int swap;
// Reads a number from the file one by one
while(fp >> num) 
{
  x[count]=num;
  count++;
  //cout << count <<". " <<num <<endl;
}


cout<<"Unsorted List:";
for(int i=0;i<count;i++){
   cout << x[i] <<" ";
}

cout << endl;

for(int j=0;j<count;j++){
    min=getmin(x,j,count);
    swap=x[j];
    x[j]=x[min];
    x[min]=swap;

}

cout << "Sorted List:";
for (int i=0;i<count;i++){
     cout << x[i]<< " ";
}
cout << endl;

fp.close();
return 0;

}



