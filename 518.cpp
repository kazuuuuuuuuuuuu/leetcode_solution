class Solution {
public:
    vector<vector<int>> memo;
    vector<int> coins;
    int change(int amount, vector<int>& coins) 
    {
        this->coins = coins;
        int n = coins.size();
        memo = vector<vector<int>> (n, vector<int> (amount+1, -1));
        return dp(n-1, amount);
    }

    int dp(int i, int curr_weight)
    {
        // i 为-1时 
        if(i<0)
        {
            // 背包容量正好为0
            if(curr_weight==0)
                return 1;
            else
                return 0;
        }

        if(memo[i][curr_weight]!=-1)
        {
            return memo[i][curr_weight];
        }

        int ans = 0;
        // 每一个状态 可以选择走到下一个物品 或者装一个该物品（前提是装得下）
        if(curr_weight>=coins[i])
        {
            ans = dp(i-1, curr_weight) + dp(i, curr_weight-coins[i]);
        }
        else
        {
            ans = dp(i-1, curr_weight);
        }
        memo[i][curr_weight] = ans;
        return ans;
    }
};