#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void printarray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // Create temporary arrays
    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = A[p + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = A[q + i + 1];
    }

    int i = 0, j = 0, k = p;
    
    // Merge the temp arrays back into A[]
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            A[k] = left[i];
            i++;
        } else {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left[], if any
    while (i < n1) {
        A[k] = left[i];
        i++;
        k++;
    }

    // Copy remaining elements of right[], if any
    while (j < n2) {
        A[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int A[], int p, int r) {
    if (p >= r) return;

    int q = p + (r - p) / 2;  // Avoids overflow
    mergesort(A, p, q);
    mergesort(A, q + 1, r);
    merge(A, p, q, r);
}

int main() {
    int x[] = {4, 5, 1, 9, 10, 2, 11, 12};
    int size = sizeof(x) / sizeof(x[0]);

    cout << "Initial Sequence:" << endl;
    printarray(x, size);

    mergesort(x, 0, size - 1);

    cout << "Sorted Sequence:" << endl;
    printarray(x, size);

    return 0;
}



