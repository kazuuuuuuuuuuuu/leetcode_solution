class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;
    int ans;

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        seen = vector<bool> (n, false);
        seen[headID] = true;
        ans = 0;
        for(int i=0;i<n;i++)
        {
            graph[manager[i]].push_back(i);
        }

        dfs(headID, informTime, 0);
        return ans;
    }

    void dfs(int i, vector<int>& informTime, int time)
    {
        time += informTime[i];
        // recursion ends
        // 到叶子节点检查是否需要修改答案
        if(graph.find(i)==graph.end())
        {
            ans = max(ans, time);
        }
        // recursively call its neighbours
        else
        {
            for(int neighbour : graph[i])
            {
                if(!seen[neighbour])
                {
                    seen[neighbour] = true;
                    dfs(neighbour, informTime, time);
                }
            }         
        }

    }
};