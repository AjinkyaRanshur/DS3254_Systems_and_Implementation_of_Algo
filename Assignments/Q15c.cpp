#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize the node
    Node(int value) : data(value), next(nullptr) {}
};

// Queue class implemented using a singly linked list
class Queue {
private:
    Node* front; // points to the front of the queue
    Node* rear;  // points to the rear of the queue

public:
    // Constructor initializes an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to free all allocated nodes
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return (front == nullptr);
    }

    // Add an element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        // If the queue is empty, both front and rear point to the new node
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Remove an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        // If the queue becomes empty after removal, update rear as well
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    // Get the front element of the queue
    int getFront() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;  // or throw an exception
        }
        return front->data;
    }

    // Get the rear element of the queue
    int getRear() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;  // or throw an exception
        }
        return rear->data;
    }
};

int main() {
    Queue q;

    // Enqueue some elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl; // Expected output: 10
    cout << "Rear element: "  << q.getRear()  << endl; // Expected output: 30

    // Dequeue an element and then check the front element again
    q.dequeue();
    cout << "Front element after dequeue: " << q.getFront() << endl; // Expected output: 20

    return 0;
}
