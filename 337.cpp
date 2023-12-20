class Solution {
public:
    unordered_map<TreeNode*, vector<int>> memo = {} ;
    int rob(TreeNode* root) 
    {
        return dp(root, true);    
    }

    // return answer to the original problems
    int dp(TreeNode* node, bool feasible)
    {
        if(node==NULL)
            return 0;

        if(memo.find(node)!=memo.end())
        {
            if(memo[node][feasible]!=-1)
                return memo[node][feasible];
        }
        else
        {
            memo[node] = {-1, -1};
        }

        // not choose this node
        int ans = 0;
        ans += dp(node->left, true);
        ans += dp(node->right, true);
        // choose this node
        if(feasible)
        {
            int ans2 = node->val;
            ans2 += dp(node->left, false);
            ans2 += dp(node->right, false);
            ans = max(ans, ans2);
        }

        memo[node][feasible] = ans;
        return ans;
    }
};