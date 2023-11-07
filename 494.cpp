// state and state transfer
// dp takes and returns
// memo
class Solution {
public:
    vector<int> nums;
    // memo的特殊格式 因为target是不确定的不能用数组来表示 -> 而是用map
    vector<unordered_map<int, int>> memo;
    int n;
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        this->nums = nums;
        n = nums.size();
        memo = vector<unordered_map<int, int>> (n, unordered_map<int, int> {});
        return dp(0, target);
    }

    int dp(int i, int sum)
    {
        // base case
        if(i==n)
        {
            // 没有元素可以使用了
            if(sum==0)
                // success
                return 1;
            else
                // lose
                return 0;
        }


        if(memo[i].find(sum)!=memo[i].end())
            return memo[i][sum];

        int ans = 0;
        int num = nums[i];
        ans += dp(i+1, sum+num);
        ans += dp(i+1, sum-num);

        memo[i][sum] = ans;
        return ans;
    }
};
