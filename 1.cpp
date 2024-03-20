class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            int num2 = target - num;
            if(map.find(num2)!=map.emd())
            {
                return {i, map[num2]};
            }
            map[num] = i;
        }
        return {-1, -1};

    }
};