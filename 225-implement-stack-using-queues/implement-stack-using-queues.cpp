class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {
        // Constructor
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        // Move all but last element from q1 to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topElement = q1.front();
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);

        return topElement;
    }
    
    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topElement = q1.front();
        q2.push(topElement); // Push it back
        q1.pop();

        swap(q1, q2);

        return topElement;
    }
    
    bool empty() {
        return q1.empty();
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