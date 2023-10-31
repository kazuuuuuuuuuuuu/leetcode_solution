class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        delete_dfs(root, target, nullptr, 2);
        return root;
    }

    // if you want to modify the original pointer
    // using &
    void delete_dfs(TreeNode* &curr, int target, TreeNode* parent, int side)
    {
        if(curr==nullptr)
            return;

        delete_dfs(curr->left, target, curr, 0);
        delete_dfs(curr->right, target, curr, 1);

        if(curr->left==nullptr&&curr->right==nullptr&&curr->val==target)
        {
            if(side==0)
                parent->left = nullptr;
            else if(side==1)
                parent->right = nullptr;
            else if(side==2)
                curr = nullptr;
        }
    }
};

// a simple version
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        delete_dfs(root, target);
        return root;
    }

    // pass by reference
    // 在该指针上直接做修改 // make modifications directly on this pointer
    void delete_dfs(TreeNode* &curr, int target)
    {
        if(curr==nullptr)
            return;

        delete_dfs(curr->left, target);
        delete_dfs(curr->right, target);

        if(curr->left==nullptr&&curr->right==nullptr&&curr->val==target)
        {
            curr = nullptr;
        }
    }
};