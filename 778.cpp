class Solution {
public:
    // 全局变量
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> grid;
    vector<vector<bool>> seen;
    int t;
    int n;

    int swimInWater(vector<vector<int>>& grid) 
    {
        n = grid.size();
        this->grid = grid;

        int left = grid[0][0];
        int right = 1000000000;

        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            seen = vector<vector<bool>>(n, vector<bool> (n, false));
            seen[0][0] = true;
            t = mid;

            // impossible possible
            if(!dfs(0, 0))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    // dfs遍历
    bool dfs(int i, int j)
    {
        if(i==n-1&&j==n-1)
            return true;
        for(auto direction : directions)
        {
            int next_i = i + direction[0];
            int next_j = j + direction[1];
            if(check(next_i, next_j)&&!seen[next_i][next_j])
            {
                seen[next_i][next_j] = true;
                if(dfs(next_i, next_j))
                    return true;
            }
        }
        return false;
    }

    // 检查是否有效
    bool check(int i, int j)
    {
        return i>=0&&i<n&&j>=0&&j<n&&grid[i][j]<=t;
    }
};