class Solution {
public:
    int m;
    int n;
    vector<vector<int>> mat;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        this->mat = mat;
        m = int(mat.size());
        n = int(mat[0].size());
        
        queue<vector<int>> queue;
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 0) {
                    queue.push({row, col, 1});
                    seen[row][col] = true;
                }
            }
        }
        
        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();
            int row = curr[0], col = curr[1], steps = curr[2];
            
            for (vector<int>& direction: directions) {
                int nextRow = row + direction[0], nextCol = col + direction[1];
                if (valid(nextRow, nextCol) && !seen[nextRow][nextCol]) {
                    seen[nextRow][nextCol] = true;
                    queue.push({nextRow, nextCol, steps + 1});
                    mat[nextRow][nextCol] = steps;
                }
            }
        }
        
        return mat;
    }
    
    bool valid(int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n && mat[row][col] == 1;
    }
};


// bfs 像水中的波浪一样 一层一层向外蔓延
// each iteration (addtional level) is an extra distance from the origin
// the origin is not necessary a node, 
// it should be the 0th level which can contain a number of elements
// 可以不仅仅是一个点 是所有level0的元素

class Solution {
public:
    int m;
    int n;
    vector<vector<int>> mat;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        m = mat.size();
        n = mat[0].size();
        // meet the requirements for the valid function
        this->mat = mat;    
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        queue<vector<int>> queue;
        // push the elements of 0th level to the queue
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    seen[i][j] = true;
                    queue.push({i, j, 1});
                }
            }
        }

        while(!queue.empty())
        {
            int layer_size = queue.size();
            // do some logic based on the layer
            // 这道题不需要这个 他已经用一个变量存储层数了
            for(int i=0;i<layer_size;i++)
            {
                int row = queue.front()[0];
                int col = queue.front()[1];
                int steps = queue.front()[2];
                queue.pop();

                for(vector<int> direction : directions)
                {
                    int next_row = row + direction[0];
                    int next_col = col + direction[1];
                    if(valid(next_row, next_col)&&!seen[next_row][next_col])
                    {
                        seen[next_row][next_col] = true;
                        queue.push({next_row, next_col, steps+1});
                        mat[next_row][next_col] = steps;
                    }
                }

            }
        }

        return mat;
    }

    bool valid(int row, int col)
    {
        return row>=0&&row<m&&col>=0&&col<n;
    }
};