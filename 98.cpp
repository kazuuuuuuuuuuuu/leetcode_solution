// check if the values of each node comply with the bst rule

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode* root, long small, long large)
    {
    	if(!root)
    		return true;
    	if((root->val<=small)||(root->val>=large))
    		return false;

    	bool left = helper(root->left, small, root->val);
    	bool right = helper(root->right, root->val, large);

    	return left&&right;
    }
};

// iterative version
bool isValidBST(TreeNode* root)
{
	if(!root)
		return true;
	// the way to pair three items 
	stack<pair<TreeNode*, pair<long, long>>> stack;
	stack.push(pair(root, pair(LONG_MIN, LONG_MAX)));

	while(!stack.empty())
	{
		auto [node, value_pair] = stack.top();
		stack.pop();
		auto [min, max] = value_pair;
		if(node->val<=min||node->val>=max)
			return false;
		if(node->left)
			stack.push(pair(node->left, pair(min, node->val)));
		if(node->right)
			stack.push(pair(node->right, pair(node->val, max)));
	}
	return true;
}