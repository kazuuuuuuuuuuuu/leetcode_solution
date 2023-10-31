class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> ans;
        vector<int> curr = {0};
        int n = graph.size();
        backtrack(n, graph, curr, ans, 0);
        return ans;
    }

    void backtrack(int n, vector<vector<int>>& graph, vector<int> &curr, vector<vector<int>> &ans, int i)
    {
        // base case
        // 最后一个元素是目标元素 加入ans
        if(curr[curr.size()-1]==n-1)
        {
            ans.push_back(curr);
            return;
        }

        for(int num : graph[i])
        {
            curr.push_back(num);
            backtrack(n, graph, curr, ans, num);
            curr.pop_back();
        }
    }
};