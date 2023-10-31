class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int n;
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        
        this->grid = grid;
        n = int(grid.size());
        vector<vector<bool>> seen(n, vector<bool>(n, false));
        queue<vector<int>> queue;
        seen[0][0] = true;
        queue.push({0, 0, 1}); // row, col, steps
        
        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();
            int row = curr[0], col = curr[1], steps = curr[2];
            if (row == n - 1 && col == n - 1) {
                return steps;
            }
            
            for (vector<int>& direction: directions) {
                int nextRow = row + direction[0], nextCol = col + direction[1];
                if (valid(nextRow, nextCol) && !seen[nextRow][nextCol]) {
                    seen[nextRow][nextCol] = true;
                    queue.push({nextRow, nextCol, steps + 1});
                }
            }
        }
        
        return -1;
    }
    
    bool valid(int row, int col) {
        return 0 <= row && row < n && 0 <= col && col < n && grid[row][col] == 0;
    }
};

class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<bool>> seen;
    // directions
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int n;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        // exceptional cases
        if(grid[0][0]==1)
            return -1;
        // initialize
        this->grid = grid;
        n = grid.size();
        seen = vector<vector<bool>>(n, vector<bool>(n, false));

        queue<vector<int>> queue;
        seen[0][0] = true;
        queue.push({0, 0, 1});

        while(!queue.empty())
        {
            vector<int> square = queue.front();
            queue.pop();

            int row = square[0];
            int col = square[1];
            int step = square[2];

            // 出栈时检查 栈中的方块 都是在用最少步数遍历到的
            if(row==n-1&&col==n-1)
                return step;

            for(vector<int> direction : directions)
            {
                int next_row = row + direction[0];
                int next_col = col + direction[1];
                int next_step = step + 1;
                if(valid(next_row, next_col)&&!seen[next_row][next_col])
                {
                    seen[next_row][next_col] = true;
                    queue.push({next_row, next_col, next_step});
                }

            }

            
        }
        return -1;
    }

    bool valid(int row, int col)
    {
        return row>=0&&row<n&&col>=0&&col<n&&grid[row][col]==0;
    }
};