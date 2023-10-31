class Solution {
public:
    // 该图为无限图
    // 深度优先遍历会访问整个连通分量中的节点
    // 遍历过程中如果遇到一个邻居还未遍历过 分配颜色
    // 遍历过的邻居检查是否符合标准

    unordered_map<int, vector<int>> graph;
    vector<int> seen;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        // 无向图
        for(vector<int> dislike : dislikes)
        {
            int i = dislike[0];
            int j = dislike[1];
            graph[i].push_back(j);
            graph[j].push_back(i);
        }

        // 该题从1到n 注意seen的长度为n+1
        seen = vector<int> (n+1, -1);

        for(int i=1;i<=n;i++)
        {
            // 没遍历过的为新的连通分量
            // 随意分配起始组号 -> 此处为0
            if(seen[i]==-1)
            {
                seen[i] = 0;
                bool check = dfs(i, 0);
                if(check==false)
                    return false;
            }
        }
        return true;
    }

    // 该dfs为新的点分配组号
    // 检查已分配的点是否满足要求
    bool dfs(int i, int group)
    {
        int next_group = 1 - group;
        for(int neighbour : graph[i])
        {
            if(seen[neighbour]==-1)
            {
                seen[neighbour] = next_group;
                bool check = dfs(neighbour, next_group);
                if(check==false)
                    return false;
            }
            else if(seen[neighbour]!=next_group)
                return false;
        }
        return true;
    }
};

