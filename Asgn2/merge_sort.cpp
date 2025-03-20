#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void printarray(int a[], int size){
        for (int i=0;i < size;i++){
            cout << a[i] <<" ";
}
        cout << endl;

}

void merge( int A[],int p, int q, int r){

    int n1= q - p + 1;

    int n2= r - q;

    //int left[n1];
    //int right[n2];
    std::vector<int> left(n1);
    std::vector<int> right(n2);

    for( int i=0;i<n1;i++){
	left[i] = A[p + i];
}

    for(int i=0; i < n2 ; i++){
	right[i]=A[q+i+1];
}
    int i=0; 
    int j=0;
    
    for(int k=p;k<=r;k++){
	if (j >= n2 || (i <n1 and left[i] <= right[j])){
		A[k] =left[i];
		i=i+1;
	}
	else{
	A[k]=right[j];
	j=j+1;
       }

    }	

}

void mergesort(int A[],int p, int r) {
    if (p >= r) return;

    int q= floor((p+r)/2);

    mergesort(A,p,q);
    mergesort(A,q+1,r);
    merge(A,p,q,r);

}

int main() {
  int x[] = {4,1,3,9,7};
  int size= sizeof(x)/ sizeof(x[0]);

  cout <<"Initial Sequence" <<endl;
  printarray(x,size);

  mergesort(x,0,size-1);
  printarray(x,size);

  cout <<"Execution of Code from below"<<endl;
  
}
  //printarray(x,size);
  //  return 0;
  //  }
