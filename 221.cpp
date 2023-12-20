// the recurrence relation is
// dp(i, j) = 1 + min(dp(i, j-1), dp(i-1, j-1), dp(i-1, j));
// i j is the coordinate of the lower right corner of that square
// dp returns the length of the side of the square
// 当前的块 由它的上 左 斜上决定 由此得到recurrence relation

class Solution {
public:
    int ans = 0;
    vector<vector<char>> arr;
    vector<vector<int>> memo;
    int maximalSquare(vector<vector<char>>& arr) 
    {
        this->arr = arr;
        int m = arr.size();
        int n = arr[0].size();
        memo = vector<vector<int>>(m, vector<int> (n, -1));
        dp(m-1, n-1);
        return ans * ans;
    }

int dp(int i, int j)
{
    // base case
    if (i < 0 || j < 0)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    int ret;
    if (arr[i][j] == '1') {
        ret = min({dp(i, j - 1), dp(i - 1, j - 1), dp(i - 1, j)}) + 1;
    }
    // arr[i][j]为0也要继续递归下去 函数不光有返回值 还有在函数内部操作的功能
    else
    {
        dp(i, j - 1); 
        dp(i - 1, j - 1);
        dp(i - 1, j);
        ret = 0;
    }
    ans = max(ans, ret);
    memo[i][j] = ret;
    return ret;
}


    
};