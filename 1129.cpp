// 这道题也是最短路径加上了新的限制
// the shortest path with an additional constraint

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        // set the graph map node -- adjacent nodes in (blue or red)
        // 不能用下面的方法 因为这个vector还没有元素 所以无法添加
        //unordered_map<int, vector<vector<int>>> graph;
        // 用两个map嵌套的结构可以解决这个问题
        unordered_map<int, unordered_map<int, vector<int>>> graph;


        //  record the states that has been seen
        // (node->color->seen or not)
        vector<vector<bool>> seen(n, vector<bool> (2, false));
        
        vector<int> ans(n, INT_MAX);

        // enter edges information
        for(vector<int> redEdge : redEdges)
        {
            int i = redEdge[0];
            int j = redEdge[1];
            graph[i][0].push_back(j);
        }
        for(vector<int> blueEdge : blueEdges)
        {
            int i = blueEdge[0];
            int j = blueEdge[1];
            graph[i][1].push_back(j);
        }

        seen[0][1] = true;
        seen[0][0] = true;;

        // queue holds the same entry as the seen set
        queue<vector<int>> queue;
        // 0th level contains two elements
        queue.push({0, 1, 0});
        queue.push({0, 0, 0});

        while(!queue.empty())
        {
            vector<int> curr = queue.front();
            queue.pop();
            int node = curr[0];
            int color = curr[1];
            int steps = curr[2];
            // updates the answer when one element is poped out
            ans[node] = min(ans[node], steps);

            for(int neighbour : graph[node][color])
            {
                if(!seen[neighbour][1-color])
                {
                    seen[neighbour][1-color] = true;
                    queue.push({neighbour, 1-color, steps+1});
                    
                }
            }
        }

        replace(ans.begin(), ans.end(), INT_MAX, -1);
        /*
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]==INT_MAX)
                ans[i] = -1;
        }
        */
        return ans;
    }
};
