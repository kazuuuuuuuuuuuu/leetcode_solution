// subarray -> hash map
class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int, int> map;
        int curr = 0;
        int ans = -1;
        // the first position
        map[0] = -1;
        for(int i=0;i<nums.size();i++)
        {
            // change curr
            int num = nums[i];
            if(num==0)
            {
                curr += -1;
            }
            else
            {
                curr += 1;
            }
            // modify map
            if(map.find(curr)==map.end())
            {
                map[curr] = i;
            }
            // modify ans
            if(map.find(curr)!=map.end())
            {
           
                int length = i - map[curr];
      
                ans = max(ans, length);
            }
        } 
        return ans;  
    }
};