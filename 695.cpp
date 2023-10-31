class Solution {
public:
    // to find all neighbours
    vector<vector<int>> directions;
    // establish the seen set
    vector<vector<bool>> seen;
    int m;
    int n;
    vector<vector<int>> grid;

    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        seen =  vector<vector<bool>>(m, vector<bool>(n, false));
        directions = {{0,-1}, {0, 1}, {1, 0}, {-1, 0}};
        int ans = 0;
        int curr;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1&&!seen[i][j])
                {
                    seen[i][j] = true;
                    curr = dfs(i, j);
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }

    int dfs(int i, int j)
    {
        int ans = 1;
        for(vector<int> direction : directions)
        {
            int x = i + direction[0];
            int y = j + direction[1];
            if(valid_square(x, y)&&!seen[x][y])
            {
                seen[x][y] = true;
                ans += dfs(x, y);
            }
        }
        return ans;
    }

    bool valid_square(int i, int j)
    {
        return i>=0&&i<m&&j>=0&&j<n&&grid[i][j]==1;
    }
};

// an iteration method
int dfs(int i, int j)
{
    int ans = 1;
    stack<pair<int, int>> stack;
    stack.push(pair(i, j));
    while(!stack.empty())
    {
        i = stack.top().first;
        j = stack.top().second;
        stack.pop();

        for(vector<int> direction : directions)
        {
            int x = i + direction[0];
            int y = j + direction[1];
            if(valid_square(x,y)&&!seen[x][y])
            {
                seen[x][y] = true;
                ans ++;
                stack.push(pair(x, y));
            }
        }
    }
    return ans;
}



