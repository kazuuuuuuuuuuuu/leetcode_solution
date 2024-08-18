class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // Adjacency List
        vector<vector<int>> graph(numCourses);
        // in_degree
        vector<int> indegree(numCourses, 0);

        for(auto& prerequisite : prerequisites)
        {
            int begin = prerequisite[1];
            int end = prerequisite[0];

            graph[begin].push_back(end);
            indegree[end]++;
        }

       
        int visited = 0;
        queue<int> to_be_visited;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                to_be_visited.push(i);
            }
        } 

        // 模拟过程 把入度为零的点从图中去掉 并加入到visited
        while(!to_be_visited.empty())
        {
            int node = to_be_visited.front();
            to_be_visited.pop();
            visited ++;

            vector<int> neighbours = graph[node];
            for(auto neighbour : neighbours)
            {
                indegree[neighbour] --;
                if(indegree[neighbour]==0)
                {
                    to_be_visited.push(neighbour);
                }
            }
        }

        return numCourses==visited;
    }
};