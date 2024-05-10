class Solution {
public:
    vector<int> nums;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->nums = nums;
        return construct(0, nums.size()-1);
    }

    TreeNode *construct(int left, int right)
    {
        if(left<right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *node = new TreeNode(nums[mid]);        
        node->left = construct(left, mid-1);
        node->right = construct(mid+1, right);
        return node;
    }
};