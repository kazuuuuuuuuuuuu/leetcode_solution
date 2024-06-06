class Solution {
public:
    vector<int> nums;
    vector<int> memo;

    int rob(vector<int>& nums) 
    {
        this->nums = nums;
        memo = vector<int> (nums.size(), -1);

        return dp(nums.size()-1);
    }

    // 考虑到i 可以获取的最大金币数
    int dp(int i)
    {
        if(i==0)
            return nums[0];
        if(i==1)
            return nums[0]>nums[1]?nums[0]:nums[1];

        if(memo[i]!=-1)
            return memo[i];
        // max（拿i处的金币，不拿i处的金币）
        int ans = max(nums[i]+dp(i-2), dp(i-1));
        memo[i] = ans;
        return ans;
    }  
};

// we only visit each state once 
// at each state, applying the recurrence relation is O(1)
// we need space to cache the results for each state 


// the bottom-up method
class Solution {
public:
    // memoize the result for each state
    int rob(vector<int>& nums) 
    {
        if(nums.size()==1)
            return nums[0];

        int n = nums.size();
        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n];
    }
};

// 以上两种算法的时间和空间复杂度都是相同的
// O(n)

// 只用两个变量储存前两种状态
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) 
        {
            return nums[0];
        }

        int prev_1 = nums[0];
        int prev_2 = max(nums[0], nums[1]);
        int curr = prev_2;

        int n = nums.size();
        for(int i=2;i<n;i++)
        {
            curr = max(prev_1+nums[i], prev_2);
            prev_1 = prev_2;
            prev_2 = curr;
        }
        return curr;

    }
};