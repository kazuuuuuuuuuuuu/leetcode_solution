class Solution {
public:
    vector<int> memo;

    int integerBreak(int n) 
    {
        memo = vector<int> (n+1, -1);  
        return dp(n);  
    }

    int dp(int num)
    {
        if(num==2)
            return 1;
        if(memo[num]!=-1)
            return memo[num];

        int ans = 0;
        for(int i=1;i<num;i++)
        {
            // 不再拆分 和继续拆分 取最大值
            int result = max(i*(num-i), i*dp(num-i));
            ans = max(ans, result);
        }
        memo[num] = ans;
        return ans;
    }
};