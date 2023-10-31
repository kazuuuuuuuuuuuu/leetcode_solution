class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int complement = target - num;
            // check if the complement exists
            // dic.find() operator in O(1) instead of O(n) as vector
            if (dic.find(complement) != dic.end()) {
                return {i, dic[complement]};
            }
            
            dic[num] = i;
        }
        
        return {-1, -1};
    }
};