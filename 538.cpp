// 二叉树中序遍历是一个有序数组 升序
// 右中左就是降序 -> 进行降序的累加
class Solution {
public:
    int pre = 0;
    TreeNode* convertBST(TreeNode* root) 
    {
        if(root==NULL) return NULL;

        convertBST(root->right);
        root->val += pre;
        pre = root->val;
        convertBST(root->left);
        return root;
    }
};