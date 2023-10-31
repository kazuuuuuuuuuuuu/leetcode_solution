class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> unique;
        int sum = 0;
        for(int num : nums)
        {
            unique[num] ++;
        }
        for(auto [key, value] : unique)
        {
            if(value==1)
                sum += key;
        }
        return sum;
    }
};