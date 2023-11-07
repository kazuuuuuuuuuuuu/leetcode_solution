// 1 monotonic stack
// 2 有一个元素大于等于栈顶元素时 栈顶元素出栈并结算 它的值时后一个元素的权重加一
// 3 站内单调递减 所以只有出栈元素前一个元素所吃的才算 后面的都看不到了
// 4 最后添加一个无穷大的元素清空栈
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) 
    {
        stack<pair<int, int>> stack;
        int n = heights.size();
        vector<int> ans(n, 0);
        heights.push_back(INT_MAX);

        for(int i=0;i<n+1;i++)
        {
            // 用来判断是否到最后一个元素
            bool flag = 0;
            if(i==n)
                flag = 1;

            // last永远保存最后一个吃的元素的权重
            int last = 0;
            bool eat = 0;
            while(!stack.empty()&&heights[stack.top().first]<=heights[i])
            {
                eat = 1;

                int index = stack.top().first;
                int consume = stack.top().second;
                stack.pop();

                
                ans[index] = last + 1;

                if(flag==1)
                    ans[index] --;

                last = consume;
            }
            if(eat==0)
                stack.push({i, 1});
            else
                stack.push({i, last+1});
        }
        return ans;

    }
};