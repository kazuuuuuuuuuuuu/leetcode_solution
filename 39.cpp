class Solution {
public:
    vector<int> candidates;
    int target;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        this->candidates = candidates;
        this->target = target;
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(ans, curr, 0, 0);
        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &curr, int sum, int start)
    {
        if(sum==target)
        {
            ans.push_back(curr);
            return;
        }

        for(int i=start;i<candidates.size();i++)
        {
            int num = candidates[i];
            if(sum+num<=target)
            {
                curr.push_back(num);
                backtrack(ans, curr, sum+num, i);
                curr.pop_back();
            }
        }
    }
};


recursion in general can be thought of as a tree
consider the maximum DEPTH of a tree
 recursion call stack 的深度将会是树的深度
