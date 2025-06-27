class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        // Rotate the queue to make the last pushed element go to the front
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
        
    }
    
    int pop() {
        
        if (!q.empty()) {
            int val = q.front();
            q.pop();
            return val;
        }
        return -1; // Or throw exception
    }
    
    int top() {
        return q.empty() ? -1 : q.front();
        
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */