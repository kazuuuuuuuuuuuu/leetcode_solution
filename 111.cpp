
// recuresion 后序遍历 大问题转换为小问题
class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(left==0&&right!=0)
            return right + 1;
        if(left!=0&&right==0)
            return left + 1;
        return 1 + min(left, right);
    }
};

// updating the minimum depth when we reach the leaf node.
class Solution {
public:
int minDepth(TreeNode* root)
{

        if (root == nullptr) {
            return 0;
        }
        
        stack<pair<TreeNode*, int>> stack;
        stack.push(pair(root, 1));
        int ans = INT_MAX;
        
        while (!stack.empty()) {
            auto [node, depth] = stack.top();
            stack.pop();
            if(node->left==NULL&&node->right==NULL)
                ans = min(ans, depth);
            
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