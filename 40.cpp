class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int *used; // 标记使用过的元素
    vector<int> candidates;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
   
        int n = candidates.size();   
        used = new int[n];
        memset(used, 0, sizeof(int) * n);
     
        backtrack(0, 0, target);
        delete [] used;
        return ans;
    }

    void backtrack(int startindex, int sum, int target) // startindex -> 之前考虑过的元素都不再考虑 避免重复
    {
        if(sum>target) return;
        if(sum==target)
        {
            ans.push_back(path);
            return;
        }

        for(int i=startindex;i<candidates.size();i++)
        {
            // 前一个相同元素没被使用过 -> 同层的相同元素 -> 去重
            if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]==0)
                continue;
            used[i] = 1;
            path.push_back(candidates[i]);
            backtrack(i+1, sum+candidates[i], target);
            path.pop_back();
            used[i] = 0;
        }
    }
};