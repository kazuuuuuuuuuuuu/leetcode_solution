// array of length n with large values
distances = [infinity] * n
distances[source] = 0

// min heap
heap = [(0, source)]

while (heap not empty) {
    curr_dist, node = heap.pop()
    if (curr_dist > distances[node]) {
        // optimization step: ignore current path if we found a better one
        continue;
    }

    for (nei, weight: [edges from node]) {
        dist = currDist + weight

        // add neighbor to heap if it creates a shorter path
        if (dist < distances[nei]) {
            distances[nei] = dist
            heap.push((dist, nei))
        }
    }
}

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int, int>> graph[n];
        for(vector<int> &flight : flights)
        {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];

            graph[from].push_back({to, price});
        }

        vector<int> steps(n, INT_MAX);
        steps[src] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
        min_heap.push({0, src, 0});
        while(!min_heap.empty())
        {
            vector<int> curr = min_heap.top();
            min_heap.pop();

            int price = curr[0];
            int to = curr[1];
            int step = curr[2];

            if(step>steps[to]||step>k+1)
                continue;
            steps[to] = step;
            if(to==dst) return price;
            for(auto next : graph[to])
            {
                int to_ = next.first;
                int price_ = next.second;
                int total = price + price_;
       
                min_heap.push({total, to_, step+1});
                
            }
        }
        return -1;
    }
};

// 这个算法专注在最小权重的边而不是边的顶点 每次拿出一个最小边