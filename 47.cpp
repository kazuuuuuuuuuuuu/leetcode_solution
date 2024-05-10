// permutation -> backtrack
// P(N, N) 的全排列
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> nums;
    int *used;

    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        this->nums = nums;
        int n = nums.size();
        used = new int[n];
        memset(used, 0, n*sizeof(int));
        backtrack();
        delete[] used;
        return ans;
    }

    void backtrack()
    {
        if(path.size()==nums.size())
        {
            ans.push_back(path);
            return;
        }

        unordered_set<int> seen; // 有重复元素 -> 用seen set做同层去重
        for(int i=0;i<nums.size();i++)
        {
            if(seen.find(nums[i])!=seen.end())
                continue;
            if(used[i]==1)
                continue;
            seen.insert(nums[i]);
            used[i] = 1;
            path.push_back(nums[i]);
            backtrack();
            used[i] = 0;
            path.pop_back();
        }
    }


};

