class Solution {
public:
    int m;
    int n;
    vector<vector<char>> grid;
    vector<vector<bool>> seen;
    // iterate over 4 neighbours
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int numIslands(vector<vector<char>>& grid) 
    {
        this->grid = grid;
        // row
        m = grid.size();
        // col
        n = grid[0].size(); 
        seen = vector(m, vector<bool>(n, false));
        
        int ans = 0;
        // traverse every node
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(gird[row][col]=='1'&&!seen[row][col])
                {
                    seen[row][col] = true;
                    ans ++;
                    dfs(row, col);
                }
            }
        }       
        return ans;
    }

    void dfs(int row, int col)
    {
        for(auto &direction : directions)
        {
            int row_ = row + direction[0];
            int col_ = col + direction[1];
            if(valid(row_, col_)&&!seen[row_][col_])
            {
                seen[row_][col_] = true;
                dfs(row_, col_);
            }
        }
    }

    bool valid(int row, int col)
    {
        return row>=0&&row<m&&col>=0&&col<n&&grid[row][col]=='1';
    }
};

// iteration dfs
void dfs(int row, int col)
{
    stack<pair<int, int>> stack;
    stack.push(pair(row, col));

    while(!stack.empty())
    {
        auto [row, col] = stack.top();
        stack.pop();

        for(vector<int> direction : directions)
        {
            int row_ = row + direction[0];
            int col_ = col + direction[1];
            if(valid(row_, col_)&&!seen[row_][col_])
            {
                seen[row_][col_] = true;
                stack.push(pair(row_, col_));
            }
        }
    }
}