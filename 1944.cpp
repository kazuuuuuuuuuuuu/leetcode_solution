//alternative 可供选择的 

// 从后往前遍历
// 用栈来保存 在当前元素之前所有可以被看到的元素
// 该元素 从中 选择所有比他小的 
// 该元素会挡住所有比他小的元素 所以进栈前 要从栈中弹出他们

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
   
    stack <int> stack;
    vector<int> ans(heights.size(), 0);

    for(int i = heights.size()-1;i>=0;i--)
    {
        // the elements in the stack 
        // are alternatives can be seen by current one under centain conditions
        if(stack.empty())
        {
            stack.push(i);
            ans[i] = 0;
        }
        else
        {
            int flag = 0;
            int count = 0;
            while(!stack.empty()&&heights[stack.top()]<heights[i])
            {
                flag = 1;
                count ++;
                stack.pop();
            }
            if(flag==1)
                ans[i] = count;
            else
                ans[i] = 1;
            stack.push(i);
        }
    }
    return ans;
    }
};