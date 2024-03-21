class Solution {
public:
    vector<int> nums;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        this->nums = nums;
        return build(0, nums.size()-1);
    }

    // 给一个区间 生成一棵树 -> 递归
    TreeNode *build(int i, int j)
    {
        int max_index;
        int max_num = INT_MIN;
        for(int k=i;k<=j;k++)
        {
            if(nums[k]>max_num)
            {
                max_num = nums[k];
                max_index = k;
            }
        }
        TreeNode *node = new TreeNode(max_num);
        // exit
        if(i==j) return node;

        int left_i = i;
        int left_j = max_index - 1;
        int right_i = max_index + 1;
        int right_j = j;
        if(left_i<=left_j)
        {
            node->left = build(left_i, left_j);
        }
        if(right_i<=right_j)
        {
            node->right = build(right_i, right_j);
        }
        return node;
    }
};