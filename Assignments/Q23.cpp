#include <iostream>
#include <vector>

class HeapSort {
private:
    std::vector<int> heap;

    void maxHeapify(int index, int size) {
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            
            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

    void buildMaxHeap() {
        int size = heap.size();
        for (int i = size / 2 - 1; i >= 0; --i) {
            maxHeapify(i, size);
        }
    }

public:
    HeapSort(std::vector<int>& arr) : heap(arr) {
        buildMaxHeap();
    }

    void sort() {
        int size = heap.size();
        for (int i = size - 1; i > 0; --i) {
            std::swap(heap[0], heap[i]);
            maxHeapify(0, i);
        }
    }

    void display() {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> arr = {10, 3, 15, 7, 8, 20, 5};
    HeapSort hs(arr);
    std::cout << "Original heap: ";
    hs.display();
    
    hs.sort();
    std::cout << "Sorted array: ";
    hs.display();
    
    return 0;
}
