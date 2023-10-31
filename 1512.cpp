class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> freq;
        for(int num : nums)
        {
            if(freq.find(num)!=freq.end())
                ans += freq[num];
            freq[num] ++;
        }
        return ans;
    }
};