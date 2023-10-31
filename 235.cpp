class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==nullptr)
            return nullptr;
        if(root==p||root==q)
            return root;
        TreeNode* cur_left = lowestCommonAncestor(root->left, p, q);
        TreeNode* cur_right = lowestCommonAncestor(root->right, p, q);
        // 两边都找到了 交点为最近祖先
        if(cur_left!=nullptr&&cur_right!=nullptr)
            return root;
        // 一个子树有发现 继续向上传递
        if(cur_left)
            return cur_left;
        if(cur_right)
            return cur_right;
        // 两个子树都没有自己也不是 返回nullptr
        return nullptr;
    }
};

// 运用bst性质的版本 仍然是找这两个点
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
            return nullptr;
        int value = root->val;
        if(value>p->val&&value>q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(value<p->val&&value<q->val)
            return lowestCommonAncestor(root->right, p, q);
        // p 和 q 不同时在左边也不同时在右边 所以该节点就是交接处
        else 
            return root;
    }
};