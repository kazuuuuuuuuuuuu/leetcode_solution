class Solution {
public:
    vector<vector<int>> questions;
    vector<long long> memo;
    int n;
    long long mostPoints(vector<vector<int>>& questions) 
    {
        this->questions = questions;
        n = questions.size();
        memo = vector<long long> (n, -1);
        return dp(0);
    }

    // what the function takes and returns?
    // 从i元素开始最多可以返回多少分数？
    long long dp(int i)
    {
        if(i>=n)
            return 0;
        if(memo[i]!=-1)
            return memo[i];

        int j = i + questions[i][1] + 1;
        long long ans = max(dp(j)+questions[i][0], dp(i+1));
        memo[i] = ans;
        return ans;

    }
};

//bottom-up
// 这个方法是从后往前
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n = questions.size();
        vector<long long> dp(n);
        dp[n-1] = questions[n-1][0];
        for(int i=n-2;i>=0;i--)
        {
            int j = i + questions[i][1] + 1;
            long long next;
            if(j>=n)
                next = 0;
            else
                next = dp[j];

            // the same recurrence relation as the top-down method
            dp[i] = max(dp[i+1], questions[i][0]+next);
        }
        return dp[0];

    }
};