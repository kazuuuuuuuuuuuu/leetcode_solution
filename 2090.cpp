// using prefix_sum array to evaluate the average in O(1)
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        if(k==0)
            return nums;        
        int n = nums.size();
        vector<int> prefix_sum(n+1 ,0);
        for(int i=0;i<n;i++)
        {
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        }    

        vector<int> ans(n, -1);

        for(int i=0;i<n;i++)
        {
            if((i-k)<0||(i+k)>=n)
                continue;
            ans[i] = (prefix_sum[i+k+1] - prefix_sum[i-k])/(2*k+1);
        }
        return ans;
    }
};