class Solution {
public:
    vector<int> prices;
    int n;
    vector<vector<vector<int>>> memo;

    int maxProfit(vector<int>& prices) 
    {
        this->prices = prices;
        n = prices.size();
        memo = vector<vector<vector<int>>> (n, vector<vector<int>> (2, vector<int> (2, INT_MAX)));
        return dp(0, 0, 0);
    }

    int dp(int i, int holding, int colddown)
    {
        if(i==n)
            return 0;
        if(memo[i][holding][colddown]!=INT_MAX)
            return memo[i][holding][colddown];

        int ans = dp(i+1, holding, 0);
        if(holding==1)
        {
            // sold out
            ans = max(ans, dp(i+1, 0, 1) + prices[i]);

        }
        else
        {
            if(colddown!=1)
                ans = max(ans, dp(i+1, 1, 0) - prices[i]);
        }
        memo[i][holding][colddown] = ans;
        return ans;
    }
};

//
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (2, 0)));

        for(int i=n-1;i>=0;i--)
        {
            for(int holding=0;holding<2;holding++)
            {
                for(int colddown=0;colddown<2;colddown++)
                {
                    int ans = dp[i+1][holding][0];
                    if(holding==1)
                    {
                        // sold out
                        ans = max(ans, dp[i+1][0][1] + prices[i]);
                    }
                    else
                    {
                        if(colddown==0)
                        {
                            // buy in
                            ans = max(ans, dp[i+1][1][1] - prices[i]);
                        }
                    }
                    dp[i][holding][colddown] = ans;
                }
            }
        }
        return dp[0][0][0];
    }
};