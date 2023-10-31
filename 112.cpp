class Solution {
public:

    int target;

    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        return fun(root, 0)
    }

    bool fun(TreeNode* root, int curr)
    {
        if(!root)
            return false;
        if(root->left==nullptr&&root->right==nullptr)
            return curr+root->val==target;
        curr += root->val;
        return fun(root->left, curr) || fun(root->right, curr);
    }
};

class Solution {
public: 
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        
        stack<pair<TreeNode*, int>> stack;
        stack.push(pair(root, 0));
        
        while (!stack.empty()) {
            auto [node, curr] = stack.top();
            stack.pop();

            if (node->left == nullptr && node->right == nullptr) {
                if (curr + node->val == targetSum) {
                    return true;
                }
            }
            
            curr += node->val;
            if (node->left != nullptr) {
                stack.push(pair(node->left, curr));
            }
            
            if (node->right != nullptr) {
                stack.push(pair(node->right, curr));
            }
        }
        
        return false;
    }
};

bool hasPathSum(TreeNode* root, int targetSum)
{
    if(!root)
        return false;
    
    stack<pair<TreeNode*, int>> stack;
    stack.push(pair(root, 0));

    while(!stack.empty())
    {
        auto [curr, sum] = stack.top();
        stack.pop();

        sum += curr->val;
        if(curr->left==nullptr&&curr->right==nullptr&&sum==targetSum)
            return true;

        if(curr->left!=nullptr)
            stack.push(pair(curr->left, sum));

        if(curr->right!=nullptr)
            stack.push(pair(curr->right, sum));
    }
    return false;

}