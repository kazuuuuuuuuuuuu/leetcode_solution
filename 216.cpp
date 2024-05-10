// 回溯 加 剪枝
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        backtrack(1, k, n, 0);
        return ans;
    }

    void backtrack(int start, int k, int n, int sum)
    {
        if(path.size()==k)
        {
            if(n==sum)
                ans.push_back(path);
            return;
        }

        for(int i=start;i<=9;i++)
        {
            if(9-i+1<k-path.size()) // 第一种剪枝
                continue;
            if(sum+i>n) // 第二种剪枝
                continue;
            path.push_back(i);
            backtrack(i+1, k, n, sum+i);
            path.pop_back();
        }
    }
};