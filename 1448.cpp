class Solution {
public:
    int goodNodes(TreeNode* root) {
        return fun(root, INT_MIN);
    }
    int fun(TreeNode* root, int maxsofar)
    {
        if(!root)
            return 0;
        int ans = 0;
        ans += fun(root->left, max(maxsofar, root->val));
        ans += fun(root->right, max(maxsofar, root->val));
        if(root->val>=maxsofar)
            ans ++;
        return ans;
    }
};

int goodNodes(TreeNode* root)
{
    if(!root)
        return 0;

    stack<pair<TreeNode*, int>> stack;
    stack.push(pair(root, INT_MIN));

    int ans = 0;

    while(!stack.empty())
    {
        auto [node, maxsofar] = stack.top();
        stack.pop();

        if(node->val>=maxsofar)
            ans ++;

        if(node->left)
            stack.push(pair(node->left, max(maxsofar, node->val)));
        if(node->right)
            stack.push(pair(node->right, max(maxsofar, node->val)));
    }
    return ans;
}

class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        stack<pair<TreeNode*, int>> stack;
        stack.push(pair(root, INT_MIN));
        int ans = 0;
        
        while (!stack.empty()) {
            auto [node, maxSoFar] = stack.top();
            stack.pop();
            
            if (node->val >= maxSoFar) {
                ans++;
            }
            
            if (node->left) {
                stack.push(pair(node->left, max(maxSoFar, node->val)));
            }
            
            if (node->right) {
                stack.push(pair(node->right, max(maxSoFar, node->val)));
            }
        }
        
        return ans;
    }
};