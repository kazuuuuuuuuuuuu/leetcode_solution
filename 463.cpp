class Solution {
public:
    vector<vector<int>> directions= {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> grid;
    int n;
    int m;
    vector<vector<bool>> seen;

    int islandPerimeter(vector<vector<int>>& grid) 
    {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        seen = vector<vector<bool>> (n, vector<bool> (m, false));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(valid(i, j))
                {
                    seen[i][j] = true;
                    return dfs(i, j);
                }
            }
        }
        return 0;
    }

    int dfs(int x, int y)
    {
        int sum = 0;
        for(vector<int> direction : directions)
        {
            int next_x = x + direction[0];
            int next_y = y + direction[1];
            // 邻居不是一个有效的陆地的话 -> 贡献一个周长
            // 超出边界 或者是水
            if(!valid(next_x, next_y))
                sum ++;
            else
            {
                if(!seen[next_x][next_y])
                {
                    seen[next_x][next_y] = true;
                    sum += dfs(next_x, next_y);
                }
            }
        }
        return sum;
    }

    bool valid(int x, int y)
    {
        return x>=0&&x<n&&y>=0&&y<m&&grid[x][y]==1;
    }
};