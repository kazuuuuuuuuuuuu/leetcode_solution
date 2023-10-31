
// 尽量维护一个monotonically increasing stack
// 在pop弹出之前查看余下的元素（输入数组剩余的和已经在栈中的）是否大于k长度
// 这样弹出后 才足够组成k长度的序列

// 接下来分为三种情况
// 弹出了 -> ans 长度小于 k -> pushback 
// 或者没有弹出 但长度本来就小于k -> pushback
// 没有弹出 但是长度等于k 什么都不做
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int total = nums.size();
        vector<int> ans;
        for(int num : nums)
        {
            while(!ans.empty()&&ans.back()>num&&total+ans.size()>k)
            {
                ans.pop_back();
            } 
            if(ans.size()<k)
                ans.push_back(num);                       
            total --;
        }
        return ans;
    }
};