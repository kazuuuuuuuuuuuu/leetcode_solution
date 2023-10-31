// uasage of a monotonic stack
//  the elements in the stack are sorted in decreasing order

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> stack;
        for(int i=0;i<temperatures.size();i++)
        {
            while(!stack.empty()&&temperatures[stack.top()]<temperatures[i])
            {
                int j = stack.top();
                stack.pop();
                ans[j] = i - j;
            }
            stack.push(i);
        }
        return ans;
    }
};