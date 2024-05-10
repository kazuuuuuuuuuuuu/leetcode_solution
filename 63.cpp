class Solution {
public:
    // i 用来遍历行 j 用来遍历列
    int i_obstacle; 
    int j_obstacle;    
    vector<vector<int>> obstacleGrid;
    vector<vector<int>> memo;

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid[0].size();
        i_obstacle = m;
        for(int i=0;i<m;i++)
        {
            if(obstacleGrid[0][i]==1)
            {
                i_obstacle = i;
                break;
            }
        }

        int n = obstacleGrid.size();        
        j_obstacle = n;
        for(int j=0;j<n;j++)
        {
            if(obstacleGrid[j][0]==1)
            {
                j_obstacle = j;
                break;
            }
        }
        memo = vector<vector<int>> (n, vector<int> (m, -1));
        this->obstacleGrid = obstacleGrid;
        return dp(m-1, n-1);
    }

    int dp(int i,  int j)
    {
        // dp数组的初始化 <-> 递归函数的base case
        if(obstacleGrid[j][i]==1)
            return 0;
        if(j==0)
        {
            if(i<i_obstacle)
                return 1;
            else
                return 0;
        }
        if(i==0)
        {
            if(j<j_obstacle)
                return 1;
            else
                return 0;
        }

        if(memo[j][i]!=-1)
            return memo[j][i];

        int ans;
        ans = dp(i-1, j) + dp(i, j-1);
        memo[j][i] = ans;

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