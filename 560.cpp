//using map to track the frequency of the prefix sum with the same value
//curr to track the current prefix sum
//to meet the condition where the prefix sum of a subsequence is equal to k
//iterate i, if curr - k is one key in the map
//then we have some subsequences that fitting the constraint
//the number of the subsequences is the frequency of that prefix sum, which is count[curr-k] 


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        int curr = 0;
        int ans = 0;
        for(int num : nums)
        {
            curr += num;
            if(count.find(curr-k)!=count.end())
                ans += count[curr-k];
            count[curr] ++;
        }
        return ans;
        
    }
};