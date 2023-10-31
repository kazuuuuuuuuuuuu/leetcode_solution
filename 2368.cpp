class Solution {
public:
    // prepare the graph
    unordered_map<int, vector<int>> graph;
    // seen set;
    vector<bool> seen;

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) 
    {
        seen =  vector<bool>(n, false);
        for(vector<int> edge : edges)
        {
            int i = edge[0];
            int j = edge[1];
            graph[i].push_back(j);
            graph[j].push_back(i);
        }

        for(int node : restricted)
            seen[node] = true;
        seen[0] = true;
        return dfs(0);
    }

    int dfs(int node)
    {
        int ans = 1;
        for(int neighbour : graph[node])
        {
            if(!seen[neighbour])
            {
                seen[neighbour] = true;
                ans += dfs(neighbour);
            }
        }
        return ans;
    }
};

// the iteration version
int dfs(int node)
{
    int ans = 1;
    stack<int> stack;
    stack.push(node);

    while(!stack.empty())
    {
        node = stack.top();
        stack.pop();
        for(int neighbour : graph[node])
        {
            if(!seen[neighbour])
            {
                seen[neighbour] = true;
                ans ++;
                stack.push(neighbour);
            }
        }
    }
    return ans;
}