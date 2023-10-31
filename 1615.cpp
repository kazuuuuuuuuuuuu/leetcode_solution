class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> graph;
        for(vector<int> road : roads)
        {
            int i = road[0];
            int j = road[1];
            graph[i].insert(j);
            graph[j].insert(i);
        }

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            int i_roads = graph[i].size();
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                int j_roads = graph[j].size();
                int sum = i_roads + j_roads;
                if(graph[i].find(j)!=graph[i].end())
                    sum --;
                ans = max(ans, sum);

            }
        }
        return ans;
    }
};