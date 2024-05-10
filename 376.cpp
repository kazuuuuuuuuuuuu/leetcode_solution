class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        if(nums.size()==1)
            return 1;

        if(nums.size()==2)
        {
            if(nums[0]==nums[1])
                return 1;
            else
                return 2;
        }

        // 数组长度3个元素起
        int ans = 1;
        bool find_first = false;
        int pre_diff;
        int curr_diff;

        for(int i=0;i<nums.size();i++)
        {
            // 去重 -> 和后一个点相同的点均不考虑
            if(nums[i]==nums[i+1])
                continue;

            // 先找去重之后第一个元素 
            if(find_first==false)
            {
                find_first = true;
                pre_diff = nums[i+1] - nums[i];
                continue;
            }

            // 最后一个元素永远是一个wiggle element
            if(i==nums.size()-1)
            {               
                ans ++;
                return ans;;            
            }

            curr_diff = nums[i+1] - nums[i];
            if(curr_diff<0&&pre_diff>0||curr_diff>0&&pre_diff<0)
            {
                ans ++;
            }  
            pre_diff = curr_diff;

        }
        // case 0 0 0 0 -> 所有元素都相等
        return ans;
    }
};