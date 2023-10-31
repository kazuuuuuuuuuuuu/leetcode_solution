// check if the root exists
// then swap the left subtree and right subtree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root!=nullptr)
        {
            TreeNode* left = invertTree(root->right);
            TreeNode* right = invertTree(root->left);
            root->left = left;
            root->right = right;
        }
        return root;
    }
};