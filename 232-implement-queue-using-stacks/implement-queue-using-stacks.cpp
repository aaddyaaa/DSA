class MyQueue {
private:
    stack<int> inStack, outStack;

    // Helper to transfer elements only when needed
    void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {
        // No initialization needed
    }
    
    void push(int x) {
        inStack.push(x);  // Enqueue to inStack
    }
    
    int pop() {
        if (outStack.empty()) {
            transfer();
        }
        int val = outStack.top();
        outStack.pop();
        return val;
    }
    
    int peek() {
        if (outStack.empty()) {
            transfer();
        }
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};