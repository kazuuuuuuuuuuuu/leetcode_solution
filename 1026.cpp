//preorder traversal

class Solution {
public:
    int ans = INT_MIN;

    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        helper(root, root->val, root->val);
        return ans;
    }

    // traverse every node
    // update the value of max, min, ans 
    void helper(TreeNode* node, int max_, int min_)
    {
        if(node==nullptr)
            return;

        // update the ans;
        int ans1 = abs(node->val-max_);
        int ans2 = abs(node->val-min_);
        ans = max(ans, ans1);
        ans = max(ans, ans2);

        // update the max_ and min_
        max_ = max(max_, node->val);
        min_ = min(min_, node->val);

        //preorder traversal
        helper(node->left, max_, min_);
        helper(node->right, max_, min_);
    }
};

//Maximum Minus Minimum
//we can record the maximum and minimum values during the recursion 
//return the difference when encountering leaves.
int maxAncestorDiff(TreeNode* root)
{
    if(root==nullptr)
        return 0;
    return helper(root, root->val, root->val);
}
int helper(TreeNode* node, int max_, int min_)
{
    // when encountering the leaves
    // reutrn abs(max_ - min_)
    if(node==nullptr)
        return abs(max_-min_);

    // 遍历其他节点时更新最大值和最小值
    max_ = max(max_, node->val);
    min_ = min(min_, node->val);
    int left = helper(node->left, max_, min_);
    int right =helper(node->right, max_, min_);

    return max(left, right);
}