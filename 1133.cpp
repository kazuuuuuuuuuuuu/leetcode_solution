// my method using hash map
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int num : nums)
            count[num] ++;

        int max = -1;
        for(auto [num, frequency] : count)
        {
            if(frequency==1)
            {
                if(num>max)
                    max = num;
            }
        }
        return max;
    }
};

// method 2 by sorting
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i=0;i<nums.size();i++)
        {
            if(i==nums.size()-1||nums[i]!=nums[i+1])
                return nums[i];
            while(i<nums.size()-1&&nums[i]==nums[i+1])
            {
                i ++;
            }
        }
        return -1;
    }
};