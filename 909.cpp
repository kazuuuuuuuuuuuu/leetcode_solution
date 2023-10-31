class Solution {
public:
    int n;
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        n = board.size(); 
        int destination = n * n;
        vector<bool> seen(n*n+1, false);
        seen[1] = true;

        queue<vector<int>> queue;
        queue.push({1, 0});

        while(!queue.empty())
        {
            vector<int> curr = queue.front();
            queue.pop();
            int label = curr[0];
            int steps = curr[1];

            if(label==destination)
                return steps;

            for(int next : next(label))
            {   // 如果有梯子的话 起点和终点两个块直接短路在一起 当作同一个块
                // 一上来就变换
                // 只检查第二个块就好了
                int dest = getDestination(next, board);
                if(!seen[dest])
                {
                    seen[dest] = true;
                    queue.push({dest, steps+1});
                }
            }

        }
        return -1;
    }

    int getDestination(int label, const vector<vector<int>>& board) {
        int row, col;
        label_2_xy(label, row, col);

        if (board[row][col] != -1)
            return board[row][col];

        return label;
    }    

    // fetch all neighbours
    vector<int> next(int curr)
    {
        vector<int> ans;
        int left = curr + 1;
        int right = min(curr + 6, n*n);
        for(;left<=right;left++)
            ans.push_back(left);
        return ans;
    }

    // translate label to coordinate
    void label_2_xy(int label, int &_row, int &_col)
    {
        int x;
        int y;
        // 所在行->向上取整
        int row = (label + (n-1)) / n;
        x = n - row;
        int col = label % n;
        // 当为奇数行时
        if(row%2==1)
        {
            if(col==0)
                y = n - 1;
            else
                y = col - 1;
        }
        // 当为偶数行时
        else
        {
            if(col==0)
                y = 0;
            else
                y = n - col; 
        }
        _row = x;
        _col = y;
    }   
};
