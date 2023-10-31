class Solution {
public:
    int deepestLeavesSum(TreeNode* root) 
    {
        if(!root)
            return 0;

        int ans;
        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty())
        {
            int sum = 0;
            int size = queue.size();

            for(int i=0;i<size;i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                sum += node->val;

                if(node->left)
                    queue.push(node->left);
                if(node->right)
                    queue.push(node->right);
            }
            ans = sum;
        }
        return ans;
    }
};