class Solution {
public:
    int max_depth;
    int ans;
    
    int findBottomLeftValue(TreeNode* root) 
    {
        max_depth = 0;
        traverse(root, 1);
        return ans;
    }

    void traverse(TreeNode* node, int depth)
    {
        if(node->left==NULL&&node->right==NULL)
        {
            if(depth>max_depth)
            {
                max_depth = depth;
                ans = node->val;
            }
            return;
        }
        // 非引用 不需要回溯
        if(node->left)
        {
            traverse(node->left, depth+1);
        }
        if(node->right)
        {
            traverse(node->right, depth+1);       
        }
    }

};