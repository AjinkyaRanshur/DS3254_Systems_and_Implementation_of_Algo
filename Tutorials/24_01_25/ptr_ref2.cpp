#include <iostream>

using namespace std;


void swap2(int *x, int *y){
     int temp= *x;
     *x = *y;
     *y = temp;
}

int main(){
    int a=5,b=6;
    cout << " a = "<< a  << " b = " << b << endl;
    swap2(&a,&b);
    cout << " a = "<< a << " b = " << b << endl ;
    return 0;
}
