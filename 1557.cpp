// evaluate the indegree of every node
// finally, insert the node with 0 indegree to the ans vector
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for(vector<int> edge : edges)
        {
            int y = edge[1];
            indegree[y] ++;
        }

        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};