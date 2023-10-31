// 一阶段用扩展版二项搜索找到两个不同状态（是否大于第一个元素）的区间的端点
// 然后在两个区间中选出一个可能的区间继续使用标准版二项搜索

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size()-1;
        int first = nums[0];
        // possible impossible
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid]>=first)
                left = mid + 1;
            else
                right = mid - 1;
        }   

        if(target>=first)
        {
            left = 0;
            //right = right;
        }   
        else
        {
            left = left;
            right = nums.size() - 1;
        }
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};