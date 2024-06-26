


// non-decreasing subsequence
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> nums;
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        this->nums = nums;
        backtrack(0);
        return ans;
    }

    void backtrack(int startindex)
    {
        if(path.size()>=2) ans.push_back(path);
        if(startindex==nums.size()) return;

        // 子序列不能打乱顺序 所以不能用sort排序 所以不能用used数组
        unordered_set<int> seen;
        for(int i=startindex;i<nums.size();i++)
        {
            // 同层去重 + 子序列必须有序 -> 两个剪枝条件
            if(seen.find(nums[i])!=seen.end()||!path.empty()&&path.back()>nums[i])
                continue;

            seen.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(i+1);
            path.pop_back();
        }
    }
};