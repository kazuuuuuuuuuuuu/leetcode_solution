class Solution {
public:
    int m;
    int n;
    vector<vector<bool>> seen;
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    vector<vector<int>> grid;
    int num_square = 1;

    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        seen = vector<vector<bool>> (m, vector<bool> (n , false));
        this->grid = grid;
        int begin_i;
        int begin_j;
        // 先把终点算在普通块里
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // break只退出本次的循环
                if(grid[i][j]==1)
                {
                    begin_i = i;
                    begin_j = j;
                }    
                else if(grid[i][j]==0)
                    num_square ++;
            }
            // 已经做了修改 ！！！ 这是上一个版本的注释 作为提示存在
            // 是由于找到了起始位置才推出的循环 而不是由于遍历完了所有j才推出的
            //if(j<n)
                //break;
        }
        seen[begin_i][begin_j] = true;
        int ans = 0;
        backtrack(ans, begin_i, begin_j, 0);
        return ans;
    }

    void backtrack(int &ans, int i, int j, int num)
    {
        if(grid[i][j]==2)
        {
            if(num==num_square)
                ans ++;
            return;
        }

        for(vector<int> &direction : directions)
        {
            int next_i = i + direction[0];
            int next_j = j + direction[1];
            if(valid(next_i, next_j)&&!seen[next_i][next_j])
            {
                seen[next_i][next_j] = true;
                backtrack(ans, next_i, next_j, num+1);
                seen[next_i][next_j] = false;
            }
        }
    }

    bool valid(int i, int j)
    {
        return i>=0&&i<m&&j>=0&&j<n&&grid[i][j]!=-1;
    }
};