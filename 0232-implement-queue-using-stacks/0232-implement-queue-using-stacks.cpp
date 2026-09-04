// Queue = FIFO, Stack = LIFO, So use 2 stacks to reverse the order.
class MyQueue {
public:
    stack<int> s1;  // main stack 
    stack<int> s2;  // To help reverse the stack
    MyQueue() {
    }
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        // Push all the elments to s2, to reverse the order
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        s2.pop();

        // Push elemenst to the main stack again (to mentain the original order after popping)
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    int peek() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        int ans = s2.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return s1.empty();
    }
};