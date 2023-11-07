class Solution {
public:
    vector<vector<int>> memo;
    int m;
    int n;
    vector<vector<int>> grid;
    int minPathSum(vector<vector<int>>& grid) 
    {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        memo = vector<vector<int>> (m, vector<int> (n, -1));
        return dp(m-1, n-1);   
    }

    int dp(int i, int j)
    {
        if(i==0&&j==0)
            return grid[i][j];
        if(memo[i][j]!=-1)
            return memo[i][j];

        int ans = INT_MAX;
        if(i>0)
        {
            ans = min(ans, dp(i-1, j));
        }
        if(j>0)
        {
            ans = min(ans, dp(i, j-1));
        }
        ans += grid[i][j];
        memo[i][j] = ans;
        return ans;
    }
};

// bottom-up
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int ans = INT_MAX;
                if(i>0)
                    ans = min(ans, dp[i-1][j]);
                if(j>0)
                    ans = min(ans, dp[i][j-1]);
                ans += grid[i][j];
                dp[i][j] = ans;
            }
        }
        return dp[m-1][n-1];
    }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, INT_MAX);

        for(int i=0;i<m;i++)
        {
            vector<int> curr = dp;
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                {
                    curr[j] = grid[i][j];
                    continue;
                }
                cout << "i, j: " << i << ",  " << j << endl;
                if(j>0)
                    curr[j] = min(curr[j], curr[j-1]);
                curr[j] += grid[i][j];
            }
            dp = curr;
        }
        return dp[n-1];
    }
};

