// two-dimension status

class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> memo;
    int rob(vector<int>& nums) 
    {
        this->nums = nums;
        n = nums.size();
        memo = vector<vector<int>>(n, vector<int>(2,-1));
        return dp(0, -1);
    }
    // 考虑i及以后所有元素
    int dp(int i, int first_is_robbed)
    {
        if(i==n-1)
        {
            if(first_is_robbed==0)
            {
                return 0;
            }
            else
            {
                return nums[n-1];
            }
        }

        if(i>n-1)
        {
            return 0;
        }

        if(i==0)
        {
            return max(dp(i+1, 1), dp(i+2, 0)+nums[0]);
        }
        
        if(memo[i][first_is_robbed]!=-1)
        {
            return memo[i][first_is_robbed];
        }

        int ans;
        ans = dp(i+1, first_is_robbed);
        ans = max(ans, dp(i+2, first_is_robbed)+nums[i]);
        memo[i][first_is_robbed] = ans;
        return ans;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        // corner case
        if(nums.size()==1)
            return nums[0];

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        // base case
        dp[n-1][1] = 0;
        dp[n-1][0] = nums[n-1];

        for(int i=n-2;i>=1;i--)
        {
            for(int j=0;j<2;j++)
            {
                int num = nums[i];
                int ans = dp[i+1][j];
                ans = max(ans, dp[i+2][j]+num);
                dp[i][j] = ans;                
            }
        }

        int ans = dp[1][0];
        ans = max(ans, dp[2][1]+nums[0]);
        return ans;
    }
        
};