// 大问题转换为小问题
// 后序遍历
int maxDepth(TreeNode* root) 
{
    if(root==NULL) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    int result = 1 + max(left, right);
    return result;        
}

// 通过前序遍历从上往下求每个节点的深度 -> 每次保存一个最大深度
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



