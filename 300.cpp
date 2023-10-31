// dp(i) return the LIS that ends with the ith element.
//  然后从0到n-1遍历一遍dp 找最大值就行了

class Solution {
public:
    vector<int> nums;
    vector<int> memo;

    int lengthOfLIS(vector<int>& nums) 
    {
        this->nums = nums;
        int n = nums.size();
        memo = vector<int> (n, -1);

        int ans = 0;
        for(int i=0;i<n;i++)
            ans = max(ans, dp(i));
        return ans;

    }

    // dicide what the dp takes and returns -> 使用元素i的subsequence们的最大长度
    // 最后只需要都遍历一边找最大值就行了

    int dp(int i)
    {
        if(memo[i]!=-1)
            return memo[i];

        // 每个元素本身就是一个subsequence
        int ans = 1;
        for(int j=0;j<i;j++)
        {
            if(nums[i]>nums[j])
            {
                ans = max(ans, dp(j)+1);
            }
        }
        // 先存储在返回
        memo[i] = ans;
        return ans;
    }
};

// the bottom up -> implementation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        // base case 
        int ans = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                    
                }
            }
            ans = max(ans, dp[i]);
            
        }
        return ans;
    }
};