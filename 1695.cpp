You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> unique;
        int right = 0, left = 0;
        int sum = 0;
        int ans = 0;
        for(;right<nums.size();right++)
        {
            int num = nums[right];
            if(unique.find(num)!=unique.end())
            {
                while(nums[left]!=num)
                {
                    unique.erase(nums[left]);
                    sum -= nums[left];
                    left ++;
                }
                unique.erase(nums[left]);
                sum -= nums[left];
                left ++;               
            }
            sum += num;
            unique.insert(num);
            ans = max(ans, sum);
        }
        return ans;
        
    }
};