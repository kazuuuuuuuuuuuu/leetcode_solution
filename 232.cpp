class MyQueue {
private:
    stack<int> forward;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        forward.push(x);
    }
    
    int pop() {
        stack<int> temp;
        while(!forward.empty())
        {
            temp.push(forward.top());
            forward.pop();         
        }    
        int ans = temp.top();
        temp.pop();
        while(!temp.empty())
        {
            forward.push(temp.top());
            temp.pop();
        }
        return ans;
    }
    
    int peek() {
        stack<int> temp;
        while(!forward.empty())
        {
            temp.push(forward.top());
            forward.pop();         
        }    
        int ans = temp.top();
        while(!temp.empty())
        {
            forward.push(temp.top());
            temp.pop();
        }
        return ans;        
    }
    
    bool empty() {
        return forward.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */