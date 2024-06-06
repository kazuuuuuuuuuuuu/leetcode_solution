class Solution {
public:
    vector<int> memo;
    vector<int> nums;
    int combinationSum4(vector<int>& nums, int target) 
    {
        this->nums = nums;
        memo = vector<int> (target+1, -1);
        return dp(target);    
    }

    // 爬楼梯升级版 每一步的步长可以是集合nums中的任意元素
    int dp(int curr)
    {
        if(curr==0) return 1;
        if(curr<0) return 0;

        if(memo[curr]!=-1) return memo[curr];

        int ans = 0;
        // 当前位置可以由 dp(curr-num)位置爬上来
        for(int num : nums)
        {
            ans += dp(curr-num);
        }
        memo[curr] = ans;
        return ans;
    }
};