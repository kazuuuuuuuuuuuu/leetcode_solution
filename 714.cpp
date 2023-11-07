// state and state transfer
// dp
// memo

class Solution {
public:
    int fee;
    int n;
    vector<vector<int>> memo;
    vector<int> prices;

    int maxProfit(vector<int>& prices, int fee) 
    {
        this->fee = fee;
        n = prices.size();
        memo = vector<vector<int>> (n, vector<int> (2, INT_MAX));
        this->prices = prices;
        return dp(0, 0);
    }

    int dp(int i, int holding)
    {
        if(i==n)
            return 0;

        if(memo[i][holding]!=INT_MAX)
            return memo[i][holding];

        // do nothing
        int ans = dp(i+1, holding);

        if(holding==1)
        {
            // sold out
            ans = max(ans, dp(i+1, 0) - fee + prices[i]);
        }
        else
        {
            // buy in
            ans = max(ans, dp(i+1, 1) - prices[i]);
        }

        memo[i][holding] = ans;
        return ans;

    }
};

// bottom up
class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        // starting from the base case

        for(int i=n-1;i>=0;i--)
        {
            for(int holding=0;holding<2;holding++)
            {
                int ans = dp[i+1][holding];
                if(holding==1)
                {
                    // sold out
                    ans = max(ans, dp[i+1][0] - fee + prices[i]);
                }
                else
                {
                    // buy in
                    ans = max(ans, dp[i+1][1] - prices[i]);
                }
                dp[i][holding] = ans;
            }
        }
        return dp[0][0];
    }
};