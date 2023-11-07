// state and state transfer
// dp takes and returns
// memo

class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<int>> memo;
    int rob(vector<int>& nums) 
    {
        n = nums.size();
        this->nums = nums;
        memo = vector<vector<int>> (n, vector<int> (2, -1));
        return dp(0, 0);
    }

    // 增加一个state variable flag记录状态
    int dp(int i, int flag)
    {
        // flag将会影响base case
        if(i==n-1)
        {
            int num = nums[i];
            if(flag==1)
                return 0;
            else
                return num;
        }
        // base case 2
        if(i>n-1)
            return 0;

        if(memo[i][flag]!=-1)
            return memo[i][flag];

        if(i==0)
        {
            int num = nums[i];
            int ans = dp(i+1, 0);;
            // do nothing
            ans = max(ans, dp(i+2, 1)+num);
            memo[i][flag] = ans;
            return ans;
        } 

        int num = nums[i];
        int ans = dp(i+1, flag);
        // do nothing
        ans = max(ans, dp(i+2, flag)+num);
        memo[i][flag] = ans;
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