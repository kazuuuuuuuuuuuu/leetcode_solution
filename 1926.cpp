class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<char>> maze;

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        this->maze = maze;
        m = maze.size();
        n = maze[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        int i = entrance[0];
        int j = entrance[1];
        seen[i][j] = true;
        queue<vector<int>> queue;
        queue.push({i, j, 0});        

        while(!queue.empty())
        {
            vector<int> curr = queue.front();
            queue.pop();

            int row = curr[0];
            int col = curr[1];
            int steps = curr[2];
            for(vector<int> direction : directions)
            {
                int next_row = row + direction[0];
                int next_col = col + direction[1];
                if(valid(next_row, next_col)&&!seen[next_row][next_col])
                {
                    if(is_exit(next_row, next_col))
                        return steps + 1;
                    seen[next_row][next_col] = true;
                    queue.push({next_row, next_col, steps+1});
                }
            }
        }
        return -1;
    }

    bool valid(int row, int col)
    {
        return row>=0&&row<m&&col>=0&&col<n&&maze[row][col]=='.';
    }

    bool is_exit(int row, int col)
    {
        return row==0||row==m-1||col==0||col==n-1;
    }
};