class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> candidates;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        this->candidates = candidates;
        backtrack(0, 0, target);
        return ans;
    }

    void backtrack(int sum, int startindex, int target)
    {
        if(sum>target)
            return;
        if(sum==target)
        {
            ans.push_back(path);
            return;
        }

        // startindex 不考虑之前已经考虑过的元素
        for(int i=startindex;i<candidates.size();i++)
        {
            if(sum+candidates[i]>target) // 剪枝
                continue;
            path.push_back(candidates[i]);
            backtrack(sum+candidates[i], i, target); // 仍然是i 可以有重复 
            path.pop_back();
        }
    }
};

recursion in general can be thought of as a tree

recursion call stack 的深度将会是树的深度
