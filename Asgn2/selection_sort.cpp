#include <iostream>

using namespace std;

int getMin(int a[], int i, int j) {
  int min = i;
  for(int k = i + 1; k <= j; k++) {
    if (a[k] < a[min]) {
      min = k;
    }
  }
  return min;
}

void printarray(int a[], int size){
	for (int i=0;i< size;i++){
	    cout << a[i] <<" ";
}
	cout << endl;

}


int main() {
  int x[] = {4, 5, 1, 9, 10, 2, 11, 12};
  int size= sizeof(x)/ sizeof(x[0]);
  cout <<"Initial Sequence" <<endl;	
  printarray(x,size);
  cout <<"Execution of Code from below"<<endl;
  for( int i=0;i<7;i++){
	int min_ind=getMin(x,i,7);
	int swap=x[i];
	x[i]=x[min_ind];
	x[min_ind]=swap;
	printarray(x,size);
	
} 
  return 0;
}
