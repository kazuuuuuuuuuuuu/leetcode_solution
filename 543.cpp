class Solution {
public:
    int ans = INT_MIN;

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        helper2(root);
        return ans - 1;

    }

    void helper2(TreeNode* node)
    {
        if(node==nullptr)
            return;
        int node_ans = helper(node->left) + helper(node->right) + 1;
        ans = max(ans, node_ans);
        
        helper2(node->left);
        helper2(node->right);
    }

    // find the longest path from the left and right subtrees
    int helper(TreeNode* node)
    {
        if(node==nullptr)
            return 0;
        int left = helper(node->left);
        int right = helper(node->right);
        return max(left, right) + 1;
    }
};