// 二叉搜索树 -> 中序遍历 -> 有序数组 
// 转换成数组看是否有序
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
		vector<int> nums;
		traverse(root, nums);
		for(int i=1;i<nums.size();i++)
		{
			if(nums[i]<=nums[i-1])
				return false;
		}
		return true;
    }

    void traverse(TreeNode *node, vector<int> &nums)
    {
    	if(node)
    	{
    		traverse(node->left,nums);
    		nums.push_back(node->val);
    		traverse(node->right,nums);
    	}
    }
};

// 不转换为数组 直接在中序遍历中判断是否大于前一个遍历的元素 用一个变量记录值
class Solution {
public:
	long long max_num = LONG_MIN;
    bool isValidBST(TreeNode* root) 
    {
    	if(root==NULL) return true;
    	bool left = isValidBST(root->left);
    	if(root->val<=max_num)
    		return false;
    	max_num = root->val;
    	bool right = isValidBST(root->right);
        return left&&right;
    }
};

// 不转换为数组 直接在中序遍历中判断是否大于前一个遍历的元素 用一个指针记录上一个节点
class Solution {
public:
	TreeNode* prev = NULL;
    bool isValidBST(TreeNode* root) 
    {
    	if(root==NULL) return true;
    	bool left = isValidBST(root->left);
    	if(prev&&root->val<=prev->val)
    		return false;
    	prev = root; // 记录这个节点 作为下一次判断的依据
    	bool right = isValidBST(root->right);
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