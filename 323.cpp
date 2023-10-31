// the number of connected components in an undirected graph
// the Number of Connected Components in an Undirected graph
class Solution {
public:
    // establish the graph
    unordered_map<int, vector<int>> graph;
    // establish the seen
    vector<bool> seen;

    int answer;

    int countComponents(int n, vector<vector<int>>& edges) 
    {
        answer = 0;
        seen = vector<bool>(n, false);
        for(vector<int> edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }        

        // traverse every node
        for(int i=0;i<n;i++)
        {
            if(!seen[i])
            {
                seen[i] = true;
                answer ++;
                dfs(i);
            }
        }
        return answer;
    }

    void dfs(int node)
    {
        for(int neighbour : graph[node])
        {
            if(!seen[neighbour])
            {
                seen[neighbour] = true;
                dfs(neighbour);
            }
        }
    }
};

// the iterative method
unordered_map<int, vector<int>> graph;
vector<bool> seen;
int countComponents(int n, vector<vector<int>>& edges) 
{

    for(vector<int> edge : edges)
    {
        int x = edge[0];
        int y = edge[1];
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    seen = vector<bool>(n, false);
    
    int ans = 0;

    for(int node=0;node<n;node++)
    {
        if(!seen[node])
        {
            seen[node] = true;
            ans ++;
            dfs(node);
        }
    }
    return ans;
}

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

