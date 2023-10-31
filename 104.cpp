class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};

int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        stack<pair<TreeNode*, int>> stack;
        stack.push(pair(root, 1));
        int ans = 0;
        
        while (!stack.empty()) {
            auto [node, depth] = stack.top();
            stack.pop();
            ans = max(ans, depth);
            
            if (node->left != nullptr) {
                stack.push(pair(node->left, depth + 1));
            }
            
            if (node -> right != nullptr) {
                stack.push(pair(node->right, depth + 1));
            }
        }
        
        return ans;
    }
};