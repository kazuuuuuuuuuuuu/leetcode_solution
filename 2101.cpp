// create an identifier for each element in the graph
// in this problem I use the index to identify a pair of coordinates
// the space complexity for call stack is O(n) where n is the number of states

class Solution 
{
public:
    vector<bool> seen;
    unordered_map<int, vector<int>> graph;

    int maximumDetonation(vector<vector<int>>& bombs)
    {
        int n = bombs.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                int x1 = bombs[i][0];
                int y1 = bombs[i][1];
                int r1 = bombs[i][2];
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                if((double)r1*r1>=(double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2))
                    graph[i].push_back(j);
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            seen = vector<bool>(n, false);
            seen[i] = true;
            ans = max(ans, dfs(i));
        }
        return ans;

    }

    int dfs(int i)
    {
        int num = 1;
        for(int neighbour : graph[i])
        {
            if(seen[neighbour]==false)
            {
                seen[neighbour] = true;
                num += dfs(neighbour);
            }
        }
        return num;
    }
};