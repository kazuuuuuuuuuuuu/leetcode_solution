// top-down dp
class Solution {
public:
    vector<int> cost;
    vector<int> memo;
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        this->cost = cost;
        memo = vector<int> (n+1, -1);
        return dp(n);    
    }

    int dp(int state)
    {
        if(state<2)
            return 0;
        // 已经计算过答案
        if(memo[state]!=-1)
            return memo[state];

        memo[state] = min(dp(state-1)+cost[state-1], dp(state-2)+cost[state-2]);
        return memo[state];
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