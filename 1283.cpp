class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        sort(nums.begin(), nums.end());
        int left = 1;
        int right = 0;
        for(int num : nums)
        {
            right = max(right, num);
        }

        // impossible possible
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(!check(nums, mid, threshold))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;

    }

    // check 函数
    bool check(vector<int> &nums, int divisor, int threshold)
    {
        int sum = 0;
        for(int num : nums)
        {
            sum += (num + divisor - 1) / divisor;
        }
        return sum <= threshold;
    }
};