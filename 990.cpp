class Solution {
public:
    unordered_map<char, vector<char>> graph;
    unordered_set<char> seen;
    bool equationsPossible(vector<string>& equations) 
    {
        unordered_map<char, vector<char>> graph2;
        for(string equation : equations)
        {
            char a = equation[0];
            char b = equation[3];
            char symbol = equation[1];
            if(symbol=='=')
            {
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
            else
            {
                if(a==b)
                    return false;
                graph2[a].push_back(b);
            }
        }

        // 使用迭代器迭代整个map
        // 查询敌对关系图
        // 如果他的敌人在邻居里 就返回false
        for(auto it=graph2.begin();it!=graph2.end();it++)
        {
            seen.clear();
            char key = it->first;
            unordered_set<char> neighbours;
            dfs(key, neighbours);
            for(char enemy : graph2[key])
            {
                if(neighbours.find(enemy)!=neighbours.end())
                    return false;
            }
        }
        return true;
        
    }

    // 找到一个点的所有邻居
    void dfs(char key, unordered_set<char> &neighbours)
    {
        for(char neighbour : graph[key])
        {
            if(seen.find(neighbour)==seen.end())
            {
                seen.insert(neighbour);
                neighbours.insert(neighbour);
                dfs(neighbour, neighbours);
            }
        }
    }
};