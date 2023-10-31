class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        vector<int> ans;
        for(int num=1;num<=9;num++)
        {
            backtrack(ans, 1, num, num, n, k);
        }
        return ans;
    }

    // 这道题因为没有引用->上下层之间没有修改
    // 同层之间也未修改变量 而是直接把修改后的结果传递到下一层
    // 综上所以并没有回退的操作
    void backtrack(vector<int> &ans, int index, int curr, int num, int n, int k)
    {
        // base case
        if(index==n)
        {
            ans.push_back(curr);
            return;
        }

        int next_num1 = num + k;
        int next_num2 = num - k;

        if(valid(next_num1))
        {
            backtrack(ans, index+1, curr*10+next_num1, next_num1, n, k);
        }

        if(valid(next_num2)&&k!=0)
        {
            backtrack(ans, index+1, curr*10+next_num2, next_num2, n, k);    
        }
    }

    bool valid(int num)
    {
        return num>=0&&num<=9;
    }
};