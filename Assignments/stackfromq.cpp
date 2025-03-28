#include <iostream>
using namespace std;

// Queue implementation
template <typename T>
class Queue {
private:
    T* arr;
    int front, rear, capacity, count;

public:
    Queue(int size) {
        capacity = size;
        arr = new T[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        if (arr) { // Prevent double deletion
            delete[] arr;
            arr = nullptr;
        }
    }

    void enqueue(T x) {
        if (count == capacity) {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
    }

    T dequeue() {
        if (is_empty()) {
            cout << "Queue Underflow" << endl;
            return -1; // Assuming T is int
        }
        T data = arr[front];
        front = (front + 1) % capacity;
        count--;
        return data;
    }

    T front_elem() {
        if (is_empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool is_empty() {
        return count == 0;
    }

    int size() {
        return count;
    }
};

// Stack implementation using two queues
template <typename T>
class StackUsingQueues {
private:
    Queue<T>* q1;
    Queue<T>* q2;
    int capacity;

public:
    StackUsingQueues(int size) {
        capacity = size;
        q1 = new Queue<T>(size);
        q2 = new Queue<T>(size);
    }

    ~StackUsingQueues() {
        delete q1;
        delete q2;
    }

    void push(T x) {
        q2->enqueue(x);

        while (!q1->is_empty()) {
            q2->enqueue(q1->dequeue());
        }

        // Swap queue pointers
        Queue<T>* temp = q1;
        q1 = q2;
        q2 = temp;
    }

    T pop() {
        if (q1->is_empty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return q1->dequeue();
    }

    T top() {
        if (q1->is_empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1->front_elem();
    }

    int size() {
        return q1->size();
    }
};

int main() {
    StackUsingQueues<int> s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Top Element: " << s.top() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    s.push(50);

    cout << "Top Element: " << s.top() << endl;
    cout << "Stack Size: " << s.size() << endl;

    return 0;
}
