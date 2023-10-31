// 经典backtrack问题 沿着整个树遍历 找到答案 添加到答案集合中
class Solution {
public:
    unordered_set<int> col_set = {};
    unordered_set<int> diagonal_set = {};
    unordered_set<int> anti_diagonal_set = {};
    int n;

    int totalNQueens(int n) 
    {
        this->n = n;
        int ans;
        ans = backtrack(0);
        return ans;
    }

    int backtrack(int row)
    {
        // base case
        if(row==n)
            return 1;

        // 经典遍历子树并将结果加起来并返回的算法
        int ans = 0;
        for(int col=0;col<n;col++)
        {
            // 关于对角线下标的两个性质
            int curr_diagonal = col - row;
            int curr_anti_diagonal = col + row;

            if(col_set.find(col)==col_set.end()&&diagonal_set.find(curr_diagonal)==diagonal_set.end()&&anti_diagonal_set.find(curr_anti_diagonal)==anti_diagonal_set.end())
            {
                col_set.insert(col);
                diagonal_set.insert(curr_diagonal);
                anti_diagonal_set.insert(curr_anti_diagonal);


                // 进入下一行 -> 下一个节点
                ans += backtrack(row + 1);

                // backtrack
                // row 不需要回退 因为未被修改 -> 只传递给下一层 并且不是引用
                col_set.erase(col);
                diagonal_set.erase(curr_diagonal);
                anti_diagonal_set.erase(curr_anti_diagonal);
            }
        }
        return ans;
    }
};