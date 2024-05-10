class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        if(root==NULL) return NULL;
        // 跳过需要裁剪的节点
        if(root->val<low)
            // 返回经过裁剪的它的右子树 
            return trimBST(root->right, low, high);
        if(root->val>high)
            // 返回经过裁剪的它的左子树 
            return trimBST(root->left, low, high); 
        root->left = trimBST(root->left, low, high); 
        root->right = trimBST(root->right, low, high);
        return root;   
    }
};