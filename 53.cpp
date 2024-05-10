// 贪心算法 -> 如果当前的subarray的和是负数就丢掉 重新开始 -> 只会让之后的和变小
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int ans = INT_MIN;
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
            ans = ans>sum?ans:sum;
            if(sum<0)
                sum = 0;
        }
        return ans;
    }
};