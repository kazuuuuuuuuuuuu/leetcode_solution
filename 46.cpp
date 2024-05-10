class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> nums;
    int *used;
    vector<vector<int>> permute(vector<int>& nums) 
    {
        this->nums = nums;
        int n = nums.size();
        used = new int[n];
        memset(used, 0, n *sizeof(int));
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

        // 不需要startindex 对于排列 之前的元素还是可以取
        for(int i=0;i<nums.size();i++)
        {
            if(used[i]==1)
                continue;
            used[i] = 1;
            path.push_back(nums[i]);
            backtrack();
            path.pop_back(); //回溯
            used[i] = 0;
        }
    }
};