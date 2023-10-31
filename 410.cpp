// 需要找到最大的subarray和 但是在历史上是最小的

class Solution {
public:
    int splitArray(vector<int>& nums, int k) 
    {
        // solution space
        int left = nums[0];
        int right = 0;
        for(int num : nums)
        {
            // 解空间的最大和最小值 在不考虑分组个数的情况下
            // 最小的最大的subarray和 即是单一的最大元素
            left = max(left, num);
            // 最大
            // 最大的最大的subarray和 既是所有元素的和 
            right += num;
        }

        // solution space distribution
        // impossible possible
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(!check(nums, k, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    // 这个测试方法非常经典
    // 选定一个最大值 可以达到吗
    // 如果选择的max所需要的最小组数是小于等于k的
    // 那么check可以返回true
    bool check(vector<int> &nums, int k, int max)
    {
        int group = 1;
        int sum = 0;
        for(int num : nums)
        {
            if(sum+num<=max)
            {
                sum += num;
            }
            else
            {
                group ++;
                sum = 0;
                sum += num;
            }
        }
        return group<=k;
    }
};