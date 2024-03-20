class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        unordered_map<int, int> map;
        for(int num1 : nums1)
        {
            for(int num2 : nums2)
            {
                int sum = num1 + num2;
                map[sum] ++;
            }
        }   

        int ans = 0;
        for(int num3 : nums3)
        {
            for(int num4 : nums4)
            {
                int target = 0 - num3 - num4;
                if(map.find(target)!=map.end())
                {
                    ans += map[target];
                }
            }
        }           
        return ans;
    }
};