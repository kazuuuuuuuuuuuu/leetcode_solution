class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        unordered_map<int, unordered_set<int>> be_trusted;
        vector<bool> condidate(n, true);
        for(vector<int> edge : trust)
        {
            int i = edge[0];
            int j =  edge[1];
            be_trusted[j].insert(i);
            condidate[i] = false;
        }

        for(int i=1;i<=n;i++)
        {
            if(be_trusted[i].size()==n-1&&condidate[i])
                return i;

        }

        return -1;
    }
};