class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) return ans;
            // get rid of the duplicate a
            if(i>0&&nums[i]==nums[i-1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left<right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum>0) right --;
                else if(sum<0) left ++;
                else
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // get rid of the duplicate b
                    while(left<right&&nums[right]==nums[right-1])
                        right --;
                    right --;
                    // get rid of the duplicate c
                    while(left<right&&nums[left]==nums[left+1])
                        left ++;
                    left ++;
                }
            }
        }
        return ans;
    }
};