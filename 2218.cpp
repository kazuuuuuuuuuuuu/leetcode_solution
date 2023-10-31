class Solution {
public:
    vector<vector<int>> piles;
    vector<vector<int>> memo;
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        this->piles = piles;
        memo = vector(piles.size(), vector(k + 1, -1));
        return dp(0, k);
    }
    
    int dp(int i, int remain)
    {
        if(i==piles.size()||remain==0)
            return 0;
        if(memo[i][remain]!=-1)
            return memo[i][remain];

        int curr = 0;
        int limit = min(remain, (int)piles[i].size());


        // take 0 coin from the current pile
        int ans = dp(i+1, remain);
        for(int j=0;j<limit;j++)
        {
            // the number of coins taken equals to j + 1;
            curr += piles[i][j];
            ans = max(ans, curr + dp(i + 1, remain - j - 1));
        }
        memo[i][remain] = ans;
        return ans;
    }
};

// bottom-up solution -> from base case

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k)
    {
        int n = piles.size();
  
        vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
        for(int i=n-1;i>=0;i--)
        {
            for(int remain=1;remain<=k;remain++)
            {
                int ans = dp[i+1][remain];
                int limit = min(remain, (int)piles[i].size());
                int curr = 0;
                for(int j=0;j<limit;j++)
                {
                    // the number of coins taken equals to j + 1;
                    curr += piles[i][j];
                    ans = max(ans, curr + dp[i + 1][remain - j - 1]);
                }
                dp[i][remain] = ans; 
            }
        }
        return dp[0][k];
    }
};