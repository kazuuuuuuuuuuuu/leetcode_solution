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
// 遍历每一个节点 确定该节点的状态 并返回给上一个节点
// 每次遍历 更改全局变量ans的值 
class Solution {
public:
    int ans = 0;
    int minCameraCover(TreeNode* root) {
        int last = traverse(root);
        if(last==2) ans ++;
        return ans;
    }

    // node status 1 -> covered, 2 -> uncovered, 0 -> have camera
    int traverse(TreeNode* node)
    {
        if(node==NULL) return 1;

        int left_status = traverse(node->left);
        int right_status = traverse(node->right);

        if(left_status==1&&right_status==1)
        {
            return 2;
        }

        if(left_status==2||right_status==2)
        {
            ans ++;
            return 0;
        }
        else if(left_status==0||right_status==0)
        {
            return 1;
        }
        return -1;
    }
};