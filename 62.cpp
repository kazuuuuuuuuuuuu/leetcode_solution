// back track 试一下
// the recursive approach is correct, but there are too many repetitive
// calculations, resulting in time limit exceeded
class Solution {
public:
    // move either down or right
    vector<vector<int>> directions = {{0, 1}, {1, 0}};
    int m;
    int n;
    int ans;
    int uniquePaths(int m, int n) 
    {
        this->m = m;
        this->n = n;
        ans = 0;
        backtrack(0, 0);
        return ans;

    }

    void backtrack(int i, int j)
    {
        if(i==m-1&&j==n-1)
        {
            ans ++;
            return;
        }
        for(vector<int> &direction : directions)
        {
            int i_next = i + direction[0];
            int j_next = j + direction[1];
            if(valid(i_next, j_next))
            {
                backtrack(i_next, j_next);
            }
        }
    }

    bool valid(int i, int j)
    {
        return i>=0&&i<m&&j>=0&&j<n;
    }
};

class Solution {
public:
    // 前一个状态
    vector<vector<int>> directions = {{0, 1}, {1, 0}};
    vector<vector<int>> memo;
    int m;
    int n;
    int uniquePaths(int m, int n) 
    {
        memo = vector<vector<int>> (m, vector<int> (n, -1));
        this->m = m;
        this->n = n;
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
        for(auto &direction : directions)
        {
            int i_prev = i - direction[0];
            int j_prev = j - direction[1];
            if(valid(i_prev, j_prev))
            {
                ans += dp(i_prev, j_prev);
            }
        }

        memo[i][j] = ans;
        return ans;

    }

    bool valid(int i, int j)
    {
        return i>=0&&i<m&&j>=0&&j<n;
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[0][0] = 1;


        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // 这句要加上不然【0】【0】 base case 被置0
                // 结果错误
                if(i==0&&j==0)
                    continue;
                int ans = 0;
                if(i>0)
                {
                    ans += dp[i-1][j];
                }
                if(j>0)
                {
                    ans += dp[i][j-1];
                }
                dp[i][j] = ans;
            }
        }
        return dp[m-1][n-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n, 0);
            for(int j=0;j<n;j++)
            {
                curr[j] = dp[j];
                if(j>0)
                    curr[j] += curr[j-1];
            }
            dp = curr;
        }
        return dp[n-1];
    }
};