class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        string curr = "(";   
        backtrack(curr, ans, n-1, 1); 
        return ans;
    }

    // 本层的left 和right并未修改 所以不需要backtrack
    void backtrack(string &curr, vector<string> &ans, int left, int right)
    {
        if(left==0&&right==0)
            ans.push_back(curr);
        
        if(left!=0)
        {
            curr += '(';
            backtrack(curr, ans, left-1, right+1);
            curr.pop_back();
        }

        if(right!=0)
        {
            curr += ')';
            backtrack(curr, ans, left, right-1);
            curr.pop_back();
        }
    }
};

// 从孩子结点回到父亲节点curr肯定是需要回退的 但是同一层的点之间共享一对 left 和 right 并且从未修改 只是在这个基础上传递给他们各自的孩子