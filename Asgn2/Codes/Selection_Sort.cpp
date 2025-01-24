#include <bits/stdc++.h>
using namespace std;

int getMin(int a[],int i,int j) {
  //The essence of this code lies in taking the starting element in an array and then comparing it against all the other elements in that array, the results of this funtion will be used in future sorting algorithims 
  int min=i;
  for(int k=i+1;k<=j;k++){
	if(a[k] < a[min]){
	   min=k;
	}
  }
  return min;
}

int Selection_Sort(){
}

int main(){
  int x[]={4,5,1,9,10,2,11,12};
  //int n=sizeof(x) /sizeof(x[0]);
  //int y=getMin(x,0,n-1);
  //cout <<"The Minmum Values of this array is " << x[y] << endl;
  //cout <<"The size of the array is " << n << endl;


}
