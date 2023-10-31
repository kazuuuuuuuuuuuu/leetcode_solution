class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        // space
        // 01 23 45 67... 89 1011 1213
        // possible impossible
        if(nums.size()==1)
            // corner case
            return nums[0];
        int left = 0;
        int right = nums.size()-1;
        right = (right % 2 == 0) ? right : right - 1;
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            mid = (mid%2==0) ? mid : mid - 1;
            if(nums[mid]==nums[mid+1])
                left = mid + 2;
            else
                right = mid - 2;
        }
        return nums[left];
    }
};