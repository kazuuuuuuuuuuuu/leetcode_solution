class Solution {
public:
    vector<int> memo;
    int climbStairs(int n) 
    {
        memo = vector<int> (n+1, -1);
        return dp(n);
    }

    int dp(int i)
    {
        if(i==1)
            return 1;
        if(i==2)
            return 2;

        if(memo[i]!=-1)
            return memo[i];

        int ans;
        ans = dp(i-1) + dp(i-2);
        memo[i] = ans;
        return ans;
    }
};

// O(n)

class Solution {
public:
    int climbStairs(int n) 
    {
        if(n==1)
            return 1;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};