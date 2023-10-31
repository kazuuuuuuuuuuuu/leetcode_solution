// method 1 by myself
// is same as the standard answer
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) 
    {
        unordered_map<int, int> num_frequency;
        for(auto arr : nums)
        {
            for(int num : arr)
                num_frequency[num] ++;
        }

        vector<int> ans;
        for(auto pair : num_frequency)
        {
            if(pair.second==nums.size()) // 如果频率等于所有数组的数量 证明出现在所有数组里
                ans.push_back(pair.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};




class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> counts;
        for (vector<int>& arr: nums) {
            for (int x: arr) {
                counts[x]++;
            }
        }
        
        int n = int(nums.size());
        vector<int> ans;
        for (auto [key, val]: counts) {
            if (val == n) {
                ans.push_back(key);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};