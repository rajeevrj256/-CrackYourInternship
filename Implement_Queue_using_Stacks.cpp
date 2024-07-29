#include <queue>

class MyQueue {
private:
    std::queue<int> myqueue;

public:
    MyQueue() {
        // Constructor is not needed here since std::queue has its own default constructor
    }
    
    void push(int x) {
        myqueue.push(x);
    }
    
    int pop() {
        if (!myqueue.empty()) {
            int frontElement = myqueue.front();
            myqueue.pop();
            return frontElement;
        } else {
            // You may want to handle this case differently, such as returning a special value or throwing an exception.
            return -1; // Example: Return -1 if the queue is empty
        }
    }
    
    int peek() {
        if (!myqueue.empty()) {
            return myqueue.front();
        } else {
            // You may want to handle this case differently, such as returning a special value or throwing an exception.
            return -1; // Example: Return -1 if the queue is empty
        }
    }
    
    bool empty() {
        return myqueue.empty();
    }
};
