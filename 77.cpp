class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) 
    {
        backtrack(1, n, k);
        return ans;
    }

    void backtrack(int start, int n, int k)
    {
        if(path.size()==k)
            ans.push_back(path);

        for(int i=start;i<=n;i++)  // for循环为同一层横向延伸
        {
            // 在同一层 处做剪枝
            if(n-i+1<k-path.size()) // 剩下待选的元素 不够组成一个完整长度的path
                continue; 
            path.push_back(i);
            backtrack(i+1, n, k); // backtrack为向下延伸
            path.pop_back();
        }
    }
};