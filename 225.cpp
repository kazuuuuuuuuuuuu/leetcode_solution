// using two queues to transfer n-1 elements 
// the remaining one is at the top of the stack
// using falg to keep track of the current active queue

class MyStack {
private:
    int flag;
    queue<int> queue_0;
    queue<int> queue_1;
public:
    MyStack() : flag(0)
    {
        
    }
    
    void push(int x) {
        if(flag==0)
            queue_0.push(x);
        else if(flag==1)
            queue_1.push(x);
    }
    
    int pop() {
        int temp;
        if(flag==0)
        {
            while(queue_0.size()>1)
            {
                temp = queue_0.front();
                queue_0.pop();
                queue_1.push(temp);
            }
            temp = queue_0.front();
            queue_0.pop();
            flag = 1;
        }
        else
        {
            while(queue_1.size()>1)
            {
                temp = queue_1.front();
                queue_1.pop();
                queue_0.push(temp);
            }
            temp = queue_1.front();
            queue_1.pop();
            flag = 0;
        }
        return temp;
    }
    
    int top() {
        int temp = this->pop();
        this->push(temp);
        return temp;
    }
    
    bool empty() {
        if(flag==0)
            return queue_0.empty();
        else
            return queue_1.empty();
    }
};