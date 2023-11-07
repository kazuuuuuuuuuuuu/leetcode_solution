// 递归 没有用memo
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> generate(int numRows) 
    {
        dp(numRows);
        return ans;
    }

    void dp(int i)
    {
        
        if(i==1)
        {
            ans.push_back({1});   
            return;
        }
        if(i==2)
        {
            dp(1);      
            ans.push_back({1, 1});
            return;
        }

        dp(i-1);
        vector<int> curr;
        curr.push_back(1);
        const vector<int> &prev = ans[i-2];
        int n = prev.size();
        for(int j=0;j<n-1;j++)
        {
            curr.push_back(prev[j]+prev[j+1]);
        }
        
        curr.push_back(1);
        ans.push_back(curr);
    }
};

// bottom-up
class Solution {
public:

    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++)
        {
            if(i==0)
            {
                ans.push_back({1});   
                continue;
            }
            if(i==1)
            {    
                ans.push_back({1, 1});
                continue;
            }

            vector<int> curr;
            curr.push_back(1);
            const vector<int> &prev = ans[i-1];
            int n = prev.size();
            for(int j=0;j<n-1;j++)
            {
                curr.push_back(prev[j]+prev[j+1]);
            }
            
            curr.push_back(1);
            ans.push_back(curr);
        }
        return ans;
    }

};