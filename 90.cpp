class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> nums;
    int *used;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        int n = nums.size();
        used = new int[n];
        memset(used, 0, n*sizeof(int));
        backtrack(0);
        delete[] used;
        return ans;
    }

    void backtrack(int startindex)
    {
        ans.push_back(path);
        if(startindex==nums.size()) return;

        for(int i=startindex;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1]&&used[i-1]==0)
                continue;

            path.push_back(nums[i]);
            used[i] = 1;
            backtrack(i+1);
            used[i] = 0;
            path.pop_back();
        }
    }
};