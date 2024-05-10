// 分成一个子集 值为总和的一半 -> 价值和重量相同的物品 一个重量为总和的背包的最大价值是否为一半 -> 重量为总和的背包的最大价值
class Solution {
public:
    vector<vector<int>> memo;
    vector<int> nums;

    bool canPartition(vector<int>& nums) 
    {
        this->nums = nums;
        int target = 0;
        for(int num : nums)
        {
            target += num;
        }    
        if(target%2!=0)
            return false;
        target = target / 2;

        int n = nums.size();
        memo = vector<vector<int>> (n, vector<int> (target+1, -1));
        return target == dp(n-1, target);
    }

    int dp(int i, int curr_weight)
    {
        if(curr_weight==0)
            return 0;
        if(i==0&&curr_weight<nums[i])
            return 0;
        if(i==0&&curr_weight>=nums[i])
            return nums[i];

        if(memo[i][curr_weight]!=-1)
            return memo[i][curr_weight];

        int ans = 0;
        if(curr_weight>=nums[i])
            ans = max(dp(i-1, curr_weight), dp(i-1, curr_weight-nums[i])+nums[i]);
        else
            ans = dp(i-1, curr_weight);

        memo[i][curr_weight] = ans;
        return ans;
    }
};