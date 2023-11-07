class Solution {
public:
    vector<int> memo;
    int tribonacci(int n) {
        memo = vector<int> (n+1, -1);
        return dp(n);
    }

    int dp(int n)
    {
        if(n==0)
            return 0;
        if(n==1||n==2)
            return 1;

        if(memo[n]!=-1)
            return memo[n];

        int ans = dp(n-1) + dp(n-2) + dp(n-3);
        memo[n] = ans;
        return ans;


    }
};


class Solution {
public:

    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1||n==2)
            return 1;
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];

    }
};