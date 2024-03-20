class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if(root) // corner case
            return traverse(root, targetSum);
        return false;
    }

    bool traverse(TreeNode* node, int curr)
    {
        // 中
        curr -= node->val;
        if(node->left==NULL&&node->right==NULL)
        {
            if(curr==0) return true;
            else return false;
        }
        //左
        if(node->left) // 非引用 不需要回溯
        {
            if(traverse(node->left,curr))
                return true;
        }
        // 右
        if(node->right)
        {
            return traverse(node->right,curr);
        }
        return false;
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

