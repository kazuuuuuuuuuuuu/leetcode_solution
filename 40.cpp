class Solution {
public:
    int target;
    vector<int> candidates;
    int n;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
    
        n = candidates.size();
        this->target = target;
        sort(candidates.begin(), candidates.end());   
        this->candidates = candidates;
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr, 0, 0);
        return ans;
    }

    // index确保排序后 只向后找candidates 不会再向前查找
    void backtrack(vector<vector<int>> &ans, vector<int> &curr, int index, int sum)
    {
        if(sum==target)
        {
            ans.push_back(curr);
            return;
        }

        int last = candidates[index];
        for(int i=index;i<n;i++)
        {
            int num = candidates[i];
            // 节点的下一个节点不能相同 相同的话直接跳过
            if(i!=index&&num==last)
                continue;
            if(num+sum<=target)
            {
                last = num;
                curr.push_back(num);
                backtrack(ans, curr, i+1, sum+num);
                curr.pop_back();
            }
        }
    }
};