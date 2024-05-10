// 此题首先默认一定有解
// 贪心算法 每次都走最大的步数
// 如果当前的cover覆盖不到终点 就再走最大的步数
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int curr_cover = 0;
        int next_cover = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            next_cover = max(next_cover, i+nums[i]);
            if(i==curr_cover)
            {
                if(i!=nums.size()-1)
                {
                    ans ++;
                    curr_cover = next_cover;
                    if(curr_cover>=nums.size()-1) break;
                }
                else 
                    break;
            }
        }    
        return ans;
    }
};