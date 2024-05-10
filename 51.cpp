class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    int n;
    
    // 判断行 对角线 反对角线是否已经有皇后存在 -> Bit Masking
    int col = 0;
    int diagonal = 0; // 行列相加恒定
    int back_diagonal = 0; // 行 + n - 列 是一个定值
    
    vector<vector<string>> solveNQueens(int n) 
    {
        this->n = n;
        backtrack(0);
        return ans;
    }

    void backtrack(int level)
    {
        if(level==n)
        {
            ans.push_back(path);
            return;
        }

        string line(n, '.');
        for(int col=0;col<n;col++)
        {
            int col_ = 1 << col;
            int diagonal_ = 1 << level + col;
            int back_diagonal_ = 1 << level + n - col;

            // 判断该位置是否合法
            if(!((this->col&col_)==0&&(this->diagonal&diagonal_)==0&&(this->back_diagonal&back_diagonal_)==0)) 
                continue;

            this->col ^= col_;
            this->diagonal ^= diagonal_;
            this->back_diagonal ^= back_diagonal_;

            line[col] = 'Q';
            path.push_back(line);
            backtrack(level+1);
            // 之后为回溯
            path.pop_back();
            line[col] = '.';

            this->col ^= col_;
            this->diagonal ^= diagonal_;
            this->back_diagonal ^= back_diagonal_;     
        }
    }
};