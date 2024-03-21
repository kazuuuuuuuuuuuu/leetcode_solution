class Solution {
public:
    // 在root1上进行更改 用上root1和root2的组件
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

class Solution {
public:
    // 构造一个新树 -> 完全用新生成的节点
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1==NULL&&root2!=NULL)
        {
            TreeNode* node = new TreeNode(root2->val);
            node->left = mergeTrees(NULL, root2->left);
            node->right = mergeTrees(NULL, root2->right);
            return node;
        }
        else if(root1!=NULL&&root2==NULL)
        {
            TreeNode* node = new TreeNode(root1->val);
            node->left = mergeTrees(root1->left, NULL);
            node->right = mergeTrees(root1->right, NULL);
            return node;
        }
        else if(root1==NULL&&root2==NULL) return NULL;

        TreeNode* node = new TreeNode(root1->val+root2->val);
        node->left = mergeTrees(root1->left, root2->left);
        node->right = mergeTrees(root1->right, root2->right);
        return node;
    }
};