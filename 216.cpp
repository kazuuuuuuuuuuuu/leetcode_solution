class Solution {
public:
    int k;
    int n;
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        this->k = k; // k numbers
        this->n = n; // sum up to n
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr, 0, 0, 1);
        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &curr, int sum, int i, int start)
    {
        // base case
        if(i==k&&sum!=n)
            return;
        if(i==k&&sum==n)
        {
            ans.push_back(curr);
            return;
        }
        for(int num=start;num<=9;num++)
        {
            if(sum+num<=n)
            {
                curr.push_back(num);
                backtrack(ans, curr, sum+num, i+1, num+1);
                curr.pop_back();
            }
        }
    }
};