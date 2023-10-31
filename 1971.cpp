class Solution {
public:
    // establish the graph 
    unordered_map<int, vector<int>> graph;
    // establish the seen set;
    vector<bool> seen;

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        for(vector<int> edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }        

        seen = vector<bool>(n, false);
        seen[source] = true;

        return dfs(source, destination);

    }
    bool dfs(int source, int destination)
    {
        if(source==destination)
            return true;
        bool ans = false;
        for(int neighbour : graph[source])
        {
            if(!seen[neighbour])
            {
                seen[neighbour] = true;
                ans = ans || dfs(neighbour, destination);
            }
        }
        return ans;
    }
};

// the iterative method
bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
{
    // exceptional case
    if(source==destination)
        return true;    
    // establish the graph
    unordered_map<int, vector<int>> graph;
    for(vector<int> edge : edges)
    {
        int x = edge[0];
        int y = edge[1];
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // establish the seen set
    vector<bool> seen(n, false);
    seen[source] = true;

    // establish the stack
    stack<int> stack;
    stack.push(source);

    while(!stack.empty())
    {
        int node = stack.top();
        stack.pop();

        for(int neighbour : graph[node])
        {
            if(neighbour==destination)
                return true;
            if(!seen[neighbour])
            {
                seen[neighbour] = true;
                stack.push(neighbour);

            }
        }
    }
    return false;
}