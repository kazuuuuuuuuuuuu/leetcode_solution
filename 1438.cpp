class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // using increasing deque to record the minimum value across the window
        deque<int> increasing;
        // using decreasing deque to record the maximum value across the window
        deque<int> decreasing;
        int left = 0;
        int right = 0;
        int ans = 0;
        for(;right<nums.size();right++)
        {
            while(!increasing.empty()&&increasing.back()>nums[right])
                increasing.pop_back();
            while(!decreasing.empty()&&decreasing.back()<nums[right])
                decreasing.pop_back();

            increasing.push_back(nums[right]);
            decreasing.push_back(nums[right]);

            while(decreasing.front()-increasing.front()>limit)
            {
                if(nums[left]==decreasing.front())
                    decreasing.pop_front();
                if(nums[left]==increasing.front())
                    increasing.pop_front();

                left ++;
            }

            ans = max(ans, right-left+1);
        }
        return ans;

    }
};