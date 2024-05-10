// top-down dp
class Solution {
public:
    vector<int> cost;
    vector<int> memo;
    int minCostClimbingStairs(vector<int>& cost) 
    {
        this->cost = cost;
        int n = cost.size();
        memo = vector<int> (n+1, -1);
        return dp(n);
    }

    int dp(int i)
    {
        if(i==0||i==1)
            return 0;
        if(memo[i]!=-1)
            return memo[i];

        int ans;
        ans = min(dp(i-1)+cost[i-1], dp(i-2)+cost[i-2]);
        memo[i] = ans;
        return ans;
    }
};
// bottom-up dp
class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) 
    {
        // 1 initialize an array dp that is sized 
        // according to the state variables
        int n = cost.size();
        vector<int> dp(n+1, 0);
        // 2 set your base cases

        // 3 write a for loop that iterate over your state variables
        for(int i=2;i<dp.size();i++)
        {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        } 

        return dp[n];
    }
};