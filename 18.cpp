class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int k=0;k<nums.size();k++)
        {
            if(k>0&&nums[k]==nums[k-1]) continue;

            for(int i=k+1;i<nums.size();i++)
            {
                if(i>k+1&&nums[i]==nums[i-1]) continue;

                int left = i + 1;
                int right = nums.size() - 1;
                while(left<right)
                {
                    long sum = long(nums[i]) + nums[left] + nums[right] + nums[k];
                    if(sum>target) right --;
                    else if(sum<target) left ++;
                    else
                    {
                        ans.push_back({nums[i], nums[left], nums[right], nums[k]});
                        // get rid of the duplicate 
                        while(left<right&&nums[right]==nums[right-1])
                            right --;
                        right --;
                        // get rid of the duplicate 
                        while(left<right&&nums[left]==nums[left+1])
                            left ++;
                        left ++;                        
                    } 
                }
            }
        } 
        return ans;   
    }
};