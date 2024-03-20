class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        // Create an adjacency table
        vector<pair<int, int>> graph[n];
        for(vector<int> &time : times)
        {
            int u = time[0] - 1;
            int v = time[1] - 1;
            int w = time[2];
            graph[u].push_back({v, w});
        }

        // Dijkstra
        k = k - 1;
        vector<int> distances(n, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.push({0, k});

        while(!min_heap.empty())
        {
            // 1 pop up one distance and one node
            auto[curr_dist, node] = min_heap.top();
            min_heap.pop();
            // 2 if it has not been visited, the distance is the shortest
            if(distances[node]!=INT_MAX)
                continue;
            distances[node] = curr_dist;
            // 3 add all its neighbours to the min_heap
            for(auto next : graph[node])
            {
                int nei = next.first;
                int weight = next.second;
                int dist = curr_dist + weight;

                min_heap.push({dist, nei});
            
            }
            
        }
        int ret = 0;
        for(int i=0;i<n;i++)
        {
            if(ret<distances[i])
                ret = distances[i];
        }
        if(ret==INT_MAX)
            return -1;
        return ret;
    }
};