class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        
        queue<vector<int>> queue;
        vector<vector<int>> seen(m, vector<int>(n, -1));
        // for seen, we can save one dimension for "remain"
        // there's no point in going back to a square we already
        // visited, but with less remaining removals
        
        queue.push({0, 0, k, 0});

        while(!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();

            int row = curr[0], col = curr[1], remain = curr[2], steps = curr[3];
            
            if (row == m - 1 && col == n - 1) {
                return steps;
            }
            
            // if the current square is an obstacle, we need to spend one of our removals
            if (grid[row][col] == 1) {
                if (remain == 0) {
                    continue;
                } else {
                    remain--;
                }
            }
            
            // if the square has already been visited, but with more removals, then the current
            // path is pointless, since more removals is better
            if (seen[row][col] >= remain) {
                continue;
            }

            seen[row][col] = remain;
            for (vector<int>& direction: directions) {
                int nextRow = row + direction[0], nextCol = col + direction[1];
                if (valid(nextRow, nextCol)) {
                    queue.push({nextRow, nextCol, remain, steps + 1});
                }
            }
        }
        
        return -1;
    }
    
    bool valid(int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n;
    }
};

// this problem contains a limitation that it requires checking the status of a vairable 

class Solution {
public:
    int m;
    int n;
    //vector<vector<int>> grid;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        //this->grid = grid;
        m = grid.size();
        n = grid[0].size();

        // seen set records the status of each square
        vector<vector<int>> seen(m, vector<int>(n, -1));
        // the queue entry holds the position（row, col）, steps, removals of one square
        queue<vector<int>> queue;
        // 0th level only contains one square as the beginning
        queue.push({0 ,0, k, 0});

        // 因为已经用一个变量记录的步数 所以在遍历时只用while循环 没有必要用for循环来分层
        // 进入栈的都是合法的
        while(!queue.empty())
        {
            vector<int> curr = queue.front();
            queue.pop();

            int row = curr[0];
            int col = curr[1];
            int removals = curr[2];
            int steps = curr[3];
            
            if(row==m-1&&col==n-1)
                return steps;

            // 先入栈再做判断
            // consider whether we should take this path
            // update the status of the current square
            // and pass this status to the next level
            if(grid[row][col]==1)
            {
                if(removals==0)
                    continue;
                else
                    removals --;
            }

            // 按照正常流程应该每个同一方块不同的状态都访问一遍 但可以做一个简化
            // 因为 更多的removal更好
            if(seen[row][col]>=removals)
            {
                continue;
            }

            seen[row][col]=removals;

            for(vector<int> direction : directions)
            {
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];
                if(valid(nextRow, nextCol))
                {
                    queue.push({nextRow, nextCol, removals, steps+1});
                }
            }


        }
        return -1;
    }

    bool valid(int row, int col)
    {
        return row>=0&&row<m&&col>=0&&col<n;
    }
};