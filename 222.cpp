// 完全二叉树 -> 左侧深度==右侧深度 -> 满二叉树 -> 直接用公式结算节点个数 -> 2^level-1
class Solution {
public:
    int countNodes(TreeNode* root) {
        // 结局 要么是空 要么是满二叉树
        // exit 1
        if(root==NULL) return 0;
        // exit 2
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftDepth = 0;
        int rightDepth = 0;
        while(left)
        {
            left = left->left;
            leftDepth ++;
        }
        while(right)
        {
            right = right->right;
            rightDepth ++;
        }

        if (leftDepth == rightDepth) {
            return (2 << leftDepth) - 1; // 注意(2<<1) 相当于2^2，所以leftDepth初始为0
        }
        // 没到结局前 大问题化为小问题
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

