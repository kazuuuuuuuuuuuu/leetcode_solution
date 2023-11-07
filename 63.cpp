//  dp -> problem -> matrix
// 1 state and state transfer
// 2 dp function
// 3 memo
class Solution {
public:
    vector<vector<int>> obstacleGrid;
    int m;
    int n;
    vector<vector<int>> memo;

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->obstacleGrid = obstacleGrid;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        memo = vector<vector<int>> (m, vector<int> (n, -1));
        if(obstacleGrid[m-1][n-1]==1)
            return 0;
        return dp(m-1, n-1);
    }

    int dp(int i, int j)
    {
        // base case
        if(i==0&&j==0)
            return 1;

        if(memo[i][j]!=-1)
            return memo[i][j];

        int ans = 0;
        if(i>0&&obstacleGrid[i-1][j]!=1)
            ans += dp(i-1, j);
        if(j>0&&obstacleGrid[i][j-1]!=1)
            ans += dp(i, j-1);

        memo[i][j] = ans;
        return ans;
    }
};

// bottom up
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));

        if(obstacleGrid[m-1][n-1]==1)
            return 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                int ans = 0;
                if(i>0&&obstacleGrid[i-1][j]!=1)
                    ans += dp[i-1][j];
                if(j>0&&obstacleGrid[i][j-1]!=1)
                    ans += dp[i][j-1];
                dp[i][j] = ans;
            }
        }
        return dp[m-1][n-1];
    }
};