// 贪心算法 -> 遍历已经可以覆盖的范围 -> 尽量扩大可覆盖的范围 如果覆盖终点就return true
// for循环条件的修改
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int cover = nums[0] + 0;
        for(int i=0;i<=cover;i++)
        {
            cover = max(cover, i+nums[i]);
            if(cover>=nums.size()-1) return true;
        }
        return false;
    }
};