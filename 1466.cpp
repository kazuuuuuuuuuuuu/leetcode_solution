
class Solution {
public:
    // transform this input to a undirected graph
    unordered_map<int, vector<int>> graph;
    // create a set to record original connections
    // unordered_set is implemented by hash table
    unordered_set<vector<int>> roads;
    // seen
    vector<bool> seen;

    int minReorder(int n, vector<vector<int>>& connections) {
        seen = vector(n, false);
        seen[0] = true;
        for(vector<int> connection : connections)
        {
            int begin = connection[0];
            int end = connection[1];
            graph[begin].push_back(end);
            graph[end].push_back(begin);
            roads.insert({begin, end});
        }

        int ans = dfs(0);
        return ans;
    }

    int dfs(int node)
    {
        int ans = 0;
        for(int neighbor : graph[node])
        {
            // 没见过的才是他的节点-》类比到binary tree
            if(!seen[neighbor])
            {
                seen[neighbor] = true;
                if(roads.find({node, neighbor})!=roads.end())
                    ans ++;
                ans += dfs(neighbor);
            }
        }
        return ans;
    }
};


// an iterative way
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        set<vector<int>> roads;
        unordered_map<int, vector<int>> graph;
        vector<bool> seen(n, false);
        
        for (vector<int>& edge: connections) {
            int x = edge[0], y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
            roads.insert({x, y});
        }
        
        int ans = 0;
        stack<int> stack;
        stack.push(0);
        seen[0] = true;
        
        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();
            
            for (int neighbor: graph[node]) {
                if (!seen[neighbor]) {
                    if (roads.find({node, neighbor}) != roads.end()) {
                        ans++;
                    }

                    seen[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }
        
        return ans;
    }
};

int minReorder(int n, vector<vector<int>>& connections)
{
    unordered_map<int, vector<int>> graph;
    vector<bool> seen(n, false);
    set<vector<int>> roads;

    for(vector<int> road : connections)
    {
        int start = road[0];
        int end = road[1];
        graph[start].push_back(end);
        graph[end].push_back(start);
        roads.insert({start, end});
    }

    seen[0] = true;
    stack<int> stack;
    stack.push(0);
    int ans = 0;

    while(!stack.empty())
    {
        int node = stack.top();
        stack.pop();

        for(int neighbor : graph[node])
        {
            if(!seen[neighbor])
            {
                if(roads.find({node, neighbor})!=roads.end())
                    ans ++;
                seen[neighbor] = true;
                stack.push(neighbor);
            }
        }

    }
    return ans;
}