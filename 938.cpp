class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        if(!root)
            return 0;
        if(root->val>=low&&root->val<=high)
            ans += root->val;

        // note that there are return values here
        if(root->val>low)
            ans += rangeSumBST(root->left, low, high);
        if(root->val<high)
            ans += rangeSumBST(root->right, low, high);

        return ans;

    }
};

// iteration version
int rangeSumBST(TreeNode* root, int low, int high)
{
    int ans = 0;
    if(!root)
        return ans;
    stack<TreeNode *> stack;
    stack.push(root);

    while(!stack.empty())
    {
        TreeNode *node = stack.top();
        stack.pop();

        if(node->val>=low&&node->val<=high)
            ans += node->val;

        if(node->val>low&&node->left!=nullptr)
            stack.push(node->left);

        if(node->val<high&&node->right!=nullptr)
            stack.push(node->right);
    }
    return ans;

}