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

int main() {
  int x[] = {4, 5, 1, 9, 10, 2, 11, 12};
  int y = getMin(x, 0, 7);
  cout << "Min is at loc " << y << " value " << x[y] << endl;
  return 0;
}
