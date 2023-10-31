class Solution {

public:

    // establish the hash map 
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // initialize the vector
        seen = vector(n, false);
        // traverse the edges in a undirected graph
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        // check every node
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(!seen[i])
            {
                seen[i] = true;
                ans ++;
                // traverse its neighbours
                dfs(i);
            }
        }
        return ans;

    }

    void dfs(int node)
    {
        for(int neighbour : graph[node])
        {
            if(!seen[neighbour])
            {
                // bfs traverse
                // the next line is needed to prevent cycles
                seen[neighbour] = true;
                bfs(neighbour);
            }
        }
    }
};

//rewrite the dfs in an iterative way
void dfs(int node)
{
    stack<int> stack;
    stack.push(node);

    while(!stack.empty())
    {
        int node = stack.top();
        stack.pop();
        for(int neighbour : graph[node])
        {
            if(!seen[neighbour])
            {
                seen[neighbour] = true;
                stack.push(neighbour);
            }
        }
    }
}
