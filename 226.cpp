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


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};