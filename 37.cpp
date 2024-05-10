// 回溯 就是 递归 -> 递归本质上就是一个状态可以发散到多个状态 -> 从一个状态回到上一个状态就叫做回溯
class Solution {
public:
    // bit masking
    int level[9] = {0};
    int col[9] = {0};
    int square[3][3] = {0};
    void solveSudoku(vector<vector<char>>& board) 
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                // 初始化一些棋盘上已有的数字
                char num = board[i][j];
                if(num=='.')
                    continue;
                
                int num_to_bit = 1 << (num-'1');
                level[i] ^= num_to_bit;
                col[j] ^= num_to_bit;
                square[i/3][j/3] ^= num_to_bit;
            }
        }
        backtrack(board);
    }

    // 所有状态都根据一个全局变量board进行判断 所以需要回溯
    bool backtrack(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                // 找到一个状态的位置 (树的一个节点)
                if(board[i][j]=='.')
                {
                    // 确定此状态的值 (确定该节点的值)
                    for(char num='1';num<='9';num++)
                    {
                        int num_to_bit = 1 << (num-'1');
                        // 判断该值是否合法
                        if( (level[i]&num_to_bit)==0 && (col[j]&num_to_bit)==0 && (square[i/3][j/3]&num_to_bit)==0 )
                        {
                            level[i] ^= num_to_bit;
                            col[j] ^= num_to_bit;
                            square[i/3][j/3] ^= num_to_bit;

                            board[i][j] = num;    
                            // 向下继续遍历搜索 (递归遍历相邻节点)
                            bool ans = backtrack(board);
                            if(ans==true) return true; 

                            // 此路径不通 -> 回溯
                            board[i][j] = '.';                       

                            level[i] ^= num_to_bit;
                            col[j] ^= num_to_bit;
                            square[i/3][j/3] ^= num_to_bit;

                        }  
                    }
                    return false;
                }
            }
        }
        return true;
    }
};

