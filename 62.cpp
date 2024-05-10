// back track 试一下 -> 正确但是超时
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

// dp
// dp数组的含义 递推关系 dp初始化 遍历顺序
class Solution {
public:
    vector<vector<int>> memo;
    int uniquePaths(int m, int n) 
    {
        memo = vector<vector<int>> (m, vector<int> (n, 0));
        return dp(m-1, n-1);
    }

    int dp(int i, int j)
    {
        if(i==0||j==0)
            return 1;

        if(memo[i][j]!=0)
            return memo[i][j];

        int ans;
        ans = dp(i, j-1) + dp(i-1, j);
        memo[i][j] = ans;
        return ans;
    }
};