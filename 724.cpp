class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int ans = -1;
        int n = nums.size();
        vector<int> prefix_sum(n+1, 0);
        for(int i=1;i<n+1;i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
        }
        for(int i=1;i<n+1;i++) // so i starts with n
        {
            // Consider the position of i (equivalent index is i - 1 in the array-nums )
            if(prefix_sum[i-1]==prefix_sum[n]-prefix_sum[i])
            {
                ans = i-1;
                break;
            }
        }
        return ans;
    }
};