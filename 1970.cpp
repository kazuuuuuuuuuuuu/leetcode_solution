// 注意 题目中所给的数组下标都是由1开始的
class Solution {
public:
    // global
    int row;
    int col;
    int day;
    vector<vector<int>> graph;
    vector<vector<bool>> seen;
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        this->row = row;
        this->col = col;
        int days = cells.size()+1;

        // 首先初始化graph 不然的话原来的input无法完成随机查找
        graph = vector<vector<int>>(row+1, vector<int>(col+1, days));
        for(int k=0;k<cells.size();k++)
        {
            int i = cells[k][0];
            int j = cells[k][1];
            graph[i][j] = k + 1;
        }


        int left = 0;
        int right = cells.size();
        while(left<=right)
        {
            // possible impossible
            int mid = left + (right - left) / 2;
            day = mid;
            if(dfs_row())
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }

    bool dfs_row()
    {
        seen = vector<vector<bool>>(row+1, vector<bool>(col+1, false));
        for(int j=1;j<=col;j++)
        {
            if (can_pass(1,j)&&!seen[1][j])
            {
                seen[1][j] = true;
                if(dfs(1, j))
                    return true;
            }
        }
        return false;
    }

    bool can_pass(int i, int j)
    {
        return day < graph[i][j];
    }

    bool dfs(int i, int j)
    {
        if(i==row)
            return true;
        for(auto direction : directions)
        {
            int next_i = i + direction[0];
            int next_j = j + direction[1];
            if(validate(next_i, next_j)&&!seen[next_i][next_j])
            {
                seen[next_i][next_j] = true;
                if(dfs(next_i, next_j))
                    return true;
            }         
        }
        return false;
    }

    bool validate(int i, int j)
    {
        return i>=1&&i<=row&&j>=1&&j<=col&&can_pass(i, j);
    }
};


