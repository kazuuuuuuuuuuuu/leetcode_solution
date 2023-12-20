class Solution {
public:
    vector<unordered_map<int, int>> memo;
    vector<int> coins;
    int change(int amount, vector<int>& coins) 
    {
        this->coins = coins;
        memo = vector<unordered_map<int, int>> (coins.size(), unordered_map<int, int> {});
        return dp(0, amount);
    }

    int dp(int i, int amount)
    {
        if(i==coins.size())
        {
            if(amount==0)
                return 1;
            else
                return 0;
        }

        if(memo[i].find(amount)!=memo[i].end())
            return memo[i][amount];

        int coin = coins[i];
        int ret = 0;
        int curr = 0;
        while(curr<=amount)
        {
            ret += dp(i+1, amount-curr);
            curr += coin;
        }
        memo[i][amount] = ret;
        return ret;
    }
};