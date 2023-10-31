//every element in a stack can record not only its value 
//but also the state of the whole stack up to that point
// 
class MinStack {
    stack<pair<int, int>> stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stack.empty())
            push({val, val});
        else
        {
            if(val<stack.top().second)
                push({val,val});
            else 
                push({val,stack.top().second});
        }
    }
    
    void pop() {
        stack.pop();
        
    }
    
    int top() {
        return stack.top().first;
    }
    
    int getMin() {
        return stack.top().second;
    }
};

