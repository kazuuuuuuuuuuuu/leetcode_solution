// 大框架是扩展的binarysearch
// 此处的check函数要用到dfs

class Solution {
public:
    vector<vector<int>> grid;
    int n, m;

    int minimumEffortPath(vector<vector<int>>& heights) 
    {
       grid =  heights;
       n = heights.size();
       m = heights[0].size();

       int left = 0;
       int right = 0;
       for(int i=0;i<n;i++)
       {
            for(int j=0;j<m;j++)
            {
                right = max(right, heights[i][j]);
            }
       }

       while(left<=right)
       {
            int mid = left + (right - left) / 2;
            // 这个区间的形状 
            // impossible possible
            // 找impossible的上界 也就是left的位置
            if(!check(mid))
                left = mid + 1;
            else
                right = mid - 1;
       }
       return left

    }

    bool valid(int row, int col)
    {
        return row>=0&&row<n&&col>=0&&col<m;
    }

    bool check(int effort)
    {
        stack<pair<int, int>> stack;
        vector<vector<int>> seen(n, vector<int>(m, false));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        stack.push(pair(0, 0));
        seen[0][0] = true;
        while(stack.size()!=0)
        {
            auto [row, col] = stack.top();
            stack.pop();

            // 出栈检查
            //遍历的退出条件
            if(row==n-1&&col==m-1)
                return true;

            //graph所有相邻节点的遍历 用seen来控制
            for(auto direction : directions)
            {
                int next_row = row + direction[0];
                int next_col = col + direction[1];

                if(valid(next_row, next_col)&&!seen[next_row][next_col])
                {
                    if(abs(grid[next_row][next_col]-grid[row][col])<=effort)
                    {
                        // 入栈调整seen
                        seen[next_row][next_col] = true;
                        stack.push(pair(next_row, next_col));
                    }
                }
            }
            return false;
        }
    } 
};

// dfs遍历时间复杂度为元素个数 空间复杂度也是元素个数
// binary search 为log
