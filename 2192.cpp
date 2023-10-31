// 这个方法利用从孩子节点向上遍历的所有点都是他的祖先的方法
// 但是需要排序

class Solution {
public:
	unordered_map<int , vector<int>> graph;
	vector<bool> seen;
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> ans;

    	// 先把整个图反过来 方向为孩子节点到父节点
    	for(vector<int> edge : edges)
    	{
    		int i = edge[0];
    		int j = edge[1];
    		graph[j].push_back(i);
    	}

    	

    	for(int i=0;i<n;i++)
        {
            seen = vector<bool> (n, false);
            seen[i] = true;
            vector<int> ancestors;
            dfs(i, ancestors);
            sort(ancestors.begin(), ancestors.end());
            ans.push_back(ancestors);
        }
        return ans;
    }

    void dfs(int n, vector<int> &ancestors)
    {
        for(int neighbour : graph[n])
        {
            if(!seen[neighbour])
            {
                seen[neighbour] = true;
                ancestors.push_back(neighbour);
                dfs(neighbour, ancestors);
            }
        }
    }
};

// 从祖先开始遍历 如果可以遍历到的话 该祖先就是可遍历到的点的其中一个祖先
// 从0 开始一直向后遍历 就可以从得到ascending的vector

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> ans(n);
        
        for(vector<int> edge : edges)
        {
            int i = edge[0];
            int j = edge[1];
            graph[i].push_back(j);
        } 

        for(int i=0;i<n;i++)
        {
            seen = vector<bool> (n, false);
            seen[i] = true;
            dfs(i, ans, i);
        }

        return ans;
    }

    void dfs(int i, vector<vector<int>> &ans, int parent)
    {
        for(int neighbour : graph[i])
        {
            if(!seen[neighbour])
            {
                seen[neighbour] = true;
                ans[neighbour].push_back(parent);
                dfs(neighbour, ans, parent);
            }
        }
    }
};