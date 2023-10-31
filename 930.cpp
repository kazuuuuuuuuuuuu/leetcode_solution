
// first create a prefix array (include the sum of 0 element)
// create a map to record the prefix sum seen before
// iterate the element in that array and find the number of prefixes equal to the current one minus goal
// append the current one to the map 
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
        {
            int n = nums.size();
            vector<int> prefix_sum(n+1);
            prefix_sum[0] = 0;
            for(int i=1;i<prefix_sum.size();i++)
            {
                prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
            }

            int ans = 0;
            unordered_map<int, int> sum_count;
            for(int x : prefix_sum)
            {
                
                if(sum_count.find(x-goal)!=sum_count.end())
                    ans += sum_count[x-goal];
                sum_count[x] ++;
            }
            return ans;
        }
};

