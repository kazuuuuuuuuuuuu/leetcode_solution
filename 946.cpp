// using a stack to simulate the operations of a stack
// for each element in the popped vector, try to pop it out
// otherwise reture false(can not pop it out)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        stack<int> test;
        for(int num : popped)
        {
            // the element to be popped is either in the pushed vector or already in the stack
            // stack can not be empty
            if(test.empty())
            {
                // pushed vector is exhausted and can not find it, return false
                if(i==pushed.size())
                    return false;
                test.push(pushed[i]);
                i ++;
            }
            // must find it in the top of the stack
            while(test.top()!=num)
            {
                // pushed vector is exhausted and can not find it, return false
                if(i==ushed.size())
                    return false;
                test.push(pushed[i]);
                i ++;
            }
            test.pop();
        }    
        return true;
    }
};