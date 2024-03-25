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
    vector<int> ans;
    int max_count = 0;
    int count = 0;
    TreeNode *prev;
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        return ans;
    }

    void traverse(TreeNode *node)
    {
        if(node)
        {
            traverse(node->left);
            if(prev==NULL||prev->val!=node->val)
                count = 1;
            else if(prev->val==node->val)
                count ++;
            prev = node;
            if(count==max_count) ans.push_back(node->val);
            else if(count>max_count)
            {
                max_count = count;
                ans.clear();
                ans.push_back(node->val);
            }
            traverse(node->right);
        }
    }
};