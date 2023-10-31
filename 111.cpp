

// recuresion
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;


        if(root->left==nullptr&&root->right==nullptr)
            return 1;

        if(root->left!=nullptr&&root->right!=nullptr)
        {
            int left = minDepth(root->left);
            int right = minDepth(root->right);

            return min(left, right) + 1;            
        }
        if(root->left!=nullptr)
            return minDepth(root->left) + 1;

        return minDepth(root->right) + 1;
    }
};

// iteration
// while updating the minimum depth when we reach the leaf node.
int minDepth(TreeNode* root)
{
    if(!root)
        return 0;
    int ans = INT_MAX;
    stack<pair<TreeNode*, int>> stack;

    stack.push(pair(root, 1));

    while(!stack.empty())
    {
        auto[node, layer] = stack.top();
        stack.pop();

        if(node->left==nullptr&&node->right==nullptr)
        {
            ans = min(ans, layer);
        }

        layer ++;

        if(node->left!=nullptr)
        {
            stack.push(pair(node->left, layer));
        }
        if(node->right!=nullptr)
        {
            stack.push(pair(node->right, layer));
        }
    }
    return ans;
}