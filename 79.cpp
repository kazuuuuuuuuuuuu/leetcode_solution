// backtrack经典题目
class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m;
    int n;
    vector<vector<char>> board;
    string word;
    vector<vector<bool>> seen;

    bool exist(vector<vector<char>>& board, string word) 
    {
        this->word = word;
        this->board = board;
        m = board.size();
        n = board[0].size();
        seen = vector<vector<bool>> (m, vector<bool> (n, false));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    seen[i][j] = true;
                    if(backtrack(i, j, 1))
                        return true;
                    // backtrack
                    seen[i][j] = false;                    
                }

            }
        }
        return false;
    }

    bool backtrack(int i, int j, int index)
    {
        // base case
        if(index==word.size())
            return true;

        for(auto &direction : directions)
        {
            int next_i = i + direction[0];
            int next_j = j + direction[1];

            if(valid(next_i, next_j)&&!seen[next_i][next_j])
            {
                if(board[next_i][next_j]==word[index])
                {
                    seen[next_i][next_j] = true;
                    // index 在这次调用中并未修改 而是直接传递给下一层 所以不需要backtrack
                    if(backtrack(next_i, next_j, index+1))
                        return true;
                    // backtrack
                    seen[next_i][next_j] = false;
                }
            }
        }
        return false;
    }

    bool valid(int i, int j)
    {
        return i>=0&&i<m&&j>=0&&j<n;
    }
};


