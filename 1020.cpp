class Solution {
public:
    vector<vector<bool>> seen;
    int n;
    int m;
    vector<vector<int>> grid;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int numEnclaves(vector<vector<int>>& grid) 
    {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        seen = vector<vector<bool>> (n, vector<bool> (m, false));

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(valid(i ,j)&&!seen[i][j])
                {
                    seen[i][j] = true;
                    int curr = 0;
                    dfs(i, j, curr);
                    if(curr!=-1)
                        ans += curr;
                }
            }
        }

        return ans;

    }

    // 遍历 整个连通分量
    // 整个连通分量共享同一个sum变量
    // 如果没有遇到边界 sum 每遍历到一个新的位置 ++
    // 如果遇到一个边界 sum被置为-1 并且再也无法更改
    void dfs(int x, int y, int &sum)
    {
        if(x==0||x==n-1||y==0||y==m-1)
        {
            sum = -1;
        }

        if(sum!=-1)
            sum ++;

        for(vector<int> direction : directions)
        {
            int x_next = x + direction[0];
            int y_next = y + direction[1];

            if(valid(x_next, y_next)&&!seen[x_next][y_next])
            {
                seen[x_next][y_next] = true;
                dfs(x_next, y_next, sum);
            }
        }
    }

    bool valid(int x, int y)
    {
        return x>=0&&x<n&&y>=0&&y<m&&grid[x][y]==1;
    }
};