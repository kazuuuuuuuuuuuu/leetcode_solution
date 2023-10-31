// 使用bfs 算最短路径
// 注意第0层是所有初始状态的集合

class Solution {
public:
    vector<vector<int>> grid;
    int n;
    int m;
    // 二维的seen set
    vector<vector<bool>> seen;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int orangesRotting(vector<vector<int>>& grid) 
    {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        seen = vector<vector<bool>> (n, vector<bool> (m, false));

        queue<pair<int, int>> queue;
        int orange = 0;
        int rotten = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    rotten ++;
                    queue.push(pair(i, j));
                    seen[i][j] = true;
                }
                else if(grid[i][j]==1)
                    orange ++;
            }
        }

        int layer = -1;

        while(!queue.empty())
        {
            layer ++;
            int length = queue.size();
            for(int i=0;i<length;i++)
            {
                auto [x, y] = queue.front();
                queue.pop();
                for(vector<int> direction : directions)
                {
                    int x_next = x + direction[0];
                    int y_next = y + direction[1];
                    if(is_orange(x_next, y_next)&&seen[x_next][y_next]==false)
                    {
                        seen[x_next][y_next] = true;
                        orange --;
                        queue.push(pair(x_next, y_next));
                    }
                }
            }
        } 
        if(rotten==0&&orange==0)
            return 0;

        if(orange!=0)
            return -1;
        
        return layer;    
    }

    bool is_orange(int x, int y)
    {
        return x>=0&&x<n&&y>=0&&y<m&&grid[x][y]==1;
    }
};