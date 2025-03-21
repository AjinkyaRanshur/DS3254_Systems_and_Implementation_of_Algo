#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1; // Stack used for enqueue operations
    stack<int> s2; // Stack used for dequeue operations

public:
    // Enqueue: Push element onto s1
    void enqueue(int x) {
        s1.push(x);
    }

    // Dequeue: Pop element from s2; if s2 is empty, transfer all elements from s1 to s2
    int dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue Underflow" << endl;
                return -1; // Or throw an exception
            }
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int result = s2.top();
        s2.pop();
        return result;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return s1.empty() && s2.empty();
    }
};

int main() {
    QueueUsingStacks q;
    
    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    // Dequeue elements
    cout << "Dequeued: " << q.dequeue() << endl; // Expected output: 10
    cout << "Dequeued: " << q.dequeue() << endl; // Expected output: 20
    
    q.enqueue(40);
    cout << "Dequeued: " << q.dequeue() << endl; // Expected output: 30
    cout << "Dequeued: " << q.dequeue() << endl; // Expected output: 40

    return 0;
}
