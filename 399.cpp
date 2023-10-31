
class Solution {
public:
    // using this structure to store weighted edges
    unordered_map<string, unordered_map<string, double>> graph;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        for(int i=0;i<n;i++)
        {
            string numertator = equations[i][0];
            string denominator = equations[i][1];
            double val = values[i];
            // undirected graph
            graph[numertator][denominator] = val;
            graph[denominator][numertator] = 1/val;
        }

        vector<double> ans;

        int m = queries.size();
        for(int i=0;i<m;i++)
        {
            string begin = queries[i][0];
            string end = queries[i][1];
            ans.push_back(dfs(begin, end));
        }
        return ans;
    }

    double dfs(string begin, string end)
    {
        if(graph.find(begin)==graph.end())
            return -1;

        // using the seen set and stack to implement dfs traverse
        // same as bfs.................
        unordered_set<string> seen;
        seen.insert(begin);
        stack<pair<string, double>> stack;
        stack.push(pair(begin, 1));

        while(!stack.empty())
        {
            auto [node, val] = stack.top();
            stack.pop();

            if(node==end)
                return val;

            for(auto [neighbour, ratio] : graph[node])
            {
                if(seen.find(neighbour)==seen.end())
                {
                    seen.insert(neighbour);
                    stack.push(pair(neighbour, val*ratio));
                }
            }
        }
        return -1;
    }
};