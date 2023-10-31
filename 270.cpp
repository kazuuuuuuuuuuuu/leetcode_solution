class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        TreeNode* node = root;
        int ans = root -> val;
        while(node!=nullptr)
        {
            if(abs(node->val-target)<abs(ans-target))
                ans = node->val;
            else if(abs(node->val-target)==abs(ans-target))
                ans = ans < node->val ? ans : node->val;

            if(node->val>target)
                node = node->left;
            else if(node->val<target)
                node = node->right;
            else
                return node->val;
        }
        return ans;
    }
};