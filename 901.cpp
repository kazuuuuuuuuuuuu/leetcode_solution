// brutal force

class StockSpanner {
private:
    stack<int> prev_price;
public:
    StockSpanner() 
    {
        
    }
    
    int next(int price) 
    {
        stack<int> temp;
        int ans = 0;
        while(!prev_price.empty()&&prev_price.top()<=price)
        {
            temp.push(prev_price.top());
            prev_price.pop();
            ans ++;
        }    

        while(!temp.empty())
        {
            prev_price.push(temp.top());
            temp.pop();
        }
        prev_price.push(price);
        ans ++;
        return ans;
    }
};

class StockSpanner {
public:
    stack<pair<int,int>> stack;
    int next(int price) {
        int ans = 1;
        // the price less than or equal to the current one 
        // will be popped out and included in the answer of the current one
        while (!stack.empty() && stack.top().first <= price) {
            ans += stack.top().second;
            stack.pop();
        }
        
        stack.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */