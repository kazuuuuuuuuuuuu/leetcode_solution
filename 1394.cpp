class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        unordered_map<int, int> lucky;
        for(int num : arr)
        {
            lucky[num] ++;
        }
        for(auto [key, value] : lucky)
        {
            if(key==value)
                ans = max(ans, key);
        }
        return ans;
    }
};