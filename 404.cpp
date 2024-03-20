class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return traverse(root, 0);
    }

    int traverse(TreeNode* node, int is_left)
    {
        // exit
        if(node==NULL) return 0;
        if(node->left==NULL&&node->right==NULL&&is_left) return node->val;
        if(node->left==NULL&&node->right==NULL&&!is_left) return 0;

        // 左  右  中 -> 大问题化成小问题
        int left = traverse(node->left, 1);
        int right = traverse(node->right, 0);
        return left + right;
    }
};