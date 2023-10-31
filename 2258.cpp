// 火没必要每次都模拟一遍 因为他的graph是固定的 所以可以提前计算好
class Solution {
public:
    int m;
    int n;
    int time;
    vector<vector<int>> fire_grid;
    vector<vector<int>> grid;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int maximumMinutes(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        this->grid = grid;
        fire_spread();

        int left = 0;
        int right = 1000000000;
        // possible impossible
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            time = mid;
            if(bfs())
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }

    void fire_spread()
    {
        this->fire_grid = vector<vector<int>> (m, vector<int> (n, INT_MAX));
        vector<vector<int>> seen(m, vector<int> (n, false));
        queue<vector<int>> queue;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    seen[i][j] = true;
                    queue.push({i, j, 0});
                }
            }
        } 

        while(!queue.empty())
        {
            vector<int> fire_unit = queue.front();
            queue.pop();

            int i = fire_unit[0];
            int j = fire_unit[1];
            int start = fire_unit[2];
            // 修改fire graph
            this->fire_grid[i][j] = start;
            for(auto &direction : directions)
            {
                int next_i = i + direction[0];
                int next_j = j + direction[1];
                if(valid(next_i, next_j)&&!seen[next_i][next_j])
                {
                    seen[next_i][next_j] = true;
                    queue.push({next_i, next_j, start+1});
                }
            }
        }
    }

    bool bfs()
    {
        queue<vector<int>> queue;
        vector<vector<bool>> seen(m, vector<bool> (n, false));

        queue.push({0, 0, time});
        seen[0][0] = true;

        while(!queue.empty())
        {
            vector<int> unit = queue.front();
            queue.pop();

            int i = unit[0];
            int j = unit[1];
            int arrive = unit[2];
        
            if(i==m-1&&j==n-1&&arrive==fire_grid[i][j])
                return true;

            // 不满足火条件
            if(arrive>=fire_grid[i][j])
                continue;            

            if(i==m-1&&j==n-1)
                return true;

            for(auto &direction : directions)
            {
                int next_i = i + direction[0];
                int next_j = j + direction[1];
                if(valid(next_i, next_j)&&!seen[next_i][next_j])
                {
                    seen[next_i][next_j] = true;
                    queue.push({next_i, next_j, arrive+1});
                }
            }
        }
        return false;
    }

    // 判断是否是一堵墙
    bool valid(int i, int j)
    {
        return i>=0&&i<m&&j>=0&&j<n&&grid[i][j]!=2;
    }
};