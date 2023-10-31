class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        long ans = 0;
        int j = 0;
        for(int i=0;i<k;i++)
        {
            if(nums[j]<0)
            {
                nums[j] = -nums[j];
                if(j<nums.size()-1&&(nums[j+1]<0 || nums[j+1]<nums[j]))
                {
                    j ++;
                }
            }
            else
                nums[j] = -nums[j];
        }
        ans = accumulate(nums.begin(), nums.end(), 0);
        return ans;
    }
};

