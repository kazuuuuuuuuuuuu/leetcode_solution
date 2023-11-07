// dp
// state and state transfer
// dp function what it takes and returns
// memo
class Solution {
public:
    vector<vector<int>> matrix;
    int m;
    int n;
    vector<vector<int>> memo;

    int minFallingPathSum(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        m = matrix.size();
        n = matrix[0].size();
        memo = vector<vector<int>> (m, vector<int> (n, INT_MAX));    
        int ans = INT_MAX;
        for(int j=0;j<n;j++)
            ans = min(ans, dp(m-1, j));
        return ans;
    }


    int dp(int i, int j)
    {
        if(i==0)
            return matrix[i][j];
        if(memo[i][j]!=INT_MAX)
            return memo[i][j];

        int ans = dp(i-1, j);
        if(j>0)
            ans = min(ans, dp(i-1, j-1));
        if(j<n-1)
            ans = min(ans, dp(i-1, j+1));
        ans += matrix[i][j];
        memo[i][j] = ans;
        return ans;
    }
};


class Solution {
public:
    
 

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    dp[i][j] = matrix[i][j];
                    continue;
                }

                int ans = dp[i-1][j];
                if(j>0)
                    ans = min(ans, dp[i-1][j-1]);
                if(j<n-1)
                    ans = min(ans, dp[i-1][j+1]);
                ans += matrix[i][j];
                dp[i][j] = ans;
            }
        }

        int ans = INT_MAX;
        for(int j=0;j<n;j++)
            ans = min(ans, dp[m-1][j]);
        return ans;
    }
};