class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int ans = gethight(root);
        return ans!=-1;
    }

    // 高度和是否平衡(-1为不平衡)用返回值一同传递
    // 一边计算每个节点的高度 一边判断是否平衡
    int gethight(TreeNode* node)
    {
        if(node==NULL)
        {
            return 0;
        }

        int left_height = gethight(node->left);
        if(left_height==-1) return -1;

        int right_height = gethight(node->right);
        if(right_height==-1) return -1;

        if(abs(left_height-right_height)>1) return -1;

        return 1 + max(left_height, right_height);

    }
};