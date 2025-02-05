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
  for( int i=1;i<7;i++){
        int key_t=x[i];
	int j=i-1;
	while (j>=0 and x[j] > key_t){
	      x[j+1]=x[j];
	      j=j-1;
	}
	x[j+1]=key_t;
	printarray(x,size);
}
  //printarray(x,size);
  return 0;
}
