

// sliding window reviews
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int i = 0;
        int result = INT_MAX;
        int sum = 0;
        int n = nums.size();

        for(int j=0;j<n;j++)
        {
            sum += nums[j];
            while(sum>=target)
            {
                // j-i+1 the size of the sliding window
                result = min(result, j-i+1);
                sum -= nums[i];
                i ++;
            }
        }
        if(result==INT_MAX)
            return 0;
        else
            return result;
    }
};

// brute force with cumulative sum vector
// easily find the sum of any subarray from i to j
class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int n = nums.size();
        if(n==0)
            return 0;
        int ans = INT_MAX;
        vector<int> sums(n);
        sums[0] = nums[0];
        for(int i=1;i<n;i++)
            sums[i] = sums[i-1] + nums[i];
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int sum = sums[j] - sums[i] + nums[i];
                if(sum>=s)
                {
                    ans = min(ans, j-i+1);
                    break;
                }

            }
        }
        return (ans==INT_MAX) ? 0 : ans;
    }
};

// method 3




int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int ans = INT_MAX;
    // prefix sum array 前n项和数组 下标代表前几个数字相加
    // sums[0] = 0 sums[1] = 前1个数相加
    vector<int> sums(n + 1, 0); // 长度为n+1， 0 ~ n 并且全部置为1
    for (int i = 1; i <= n; i++)
        sums[i] = sums[i - 1] + nums[i - 1]; // 前i个数和 第i个数在nums的下标为i-1
    // 遍历sums 从0个数的和 到 n-1个数的和
    for (int i = 0; i <= n-1; i++) {
        int to_find = s + sums[i];
        // 找个第一个位置 该位置的值大于等于to_find
        // a >= b + target 则 a - b >= target 满足条件
        auto bound = lower_bound(sums.begin(), sums.end(), to_find);
        if (bound != sums.end()) {
            ans = min(ans, static_cast<int>(bound - (sums.begin() + i)));
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}