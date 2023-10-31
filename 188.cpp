// dp -> first determine the state variables and recurrence relation
// what dp function takes and returns
class Solution {
public:
    vector<int> prices;
    int n;
    vector<vector<vector<int>>> memo;
    int maxProfit(int k, vector<int>& prices) 
    {
        this->prices = prices;
        n = prices.size();
        memo = vector<vector<vector<int>>> (n, vector<vector<int>> (k+1, vector<int> (2, INT_MAX)));
        return dp(0, k, 0);
    }

    int dp(int i, int k, int holding)
    {
        // base case
        if(i==n||k==0)
            return 0;

        if(memo[i][k][holding]==INT_MAX)
            return memo[i][k][holding];
        int ans;
        if(holding==1)
        {
            ans = max(dp(i+1, k, holding), dp(i+1, k-1, 1-holding)+prices[i]);
        }
        else
        {
            ans = max(dp(i+1, k, holding), dp(i+1, k, 1-holding)-prices[i]);
        }
        memo[i][k][holding] = ans;
        return ans;
    }
};

// start iteration from the base case
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (k+1, vector<int> (2, 0)));
        // base case 自动取0了 
        // 从base case之前的状态开始 往前推
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=k;j++)
            {
                for(int holding=0;holding<2;holding++)
                {
                    if(holding==1)
                    {
                        dp[i][j][holding] = max(dp[i+1][j][holding], dp[i+1][j-1][1-holding]+prices[i]);
                    }
                    else
                    {
                        dp[i][j][holding] = max(dp[i+1][j][holding], dp[i+1][j][1-holding]-prices[i]);
                    }
                }
            }
        }
        return dp[0][k][0];
    }
};