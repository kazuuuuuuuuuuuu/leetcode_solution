class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int curr_sum = 0;
        int max_sum = INT_MIN;
        int ans = 0;
        queue<TreeNode*> queue;
        queue.push(root);

        int layer = 0;
        while(!queue.empty())
        {
            layer ++;
            int length = queue.size();
            curr_sum = 0;
            for(int i=0;i<length;i++)
            {
                TreeNode *curr = queue.front();
                queue.pop();
                curr_sum += curr->val;
                if(curr->left)
                    queue.push(curr->left);
                if(curr->right)
                    queue.push(curr->right); 
            }
            if(curr_sum>max_sum)
            {
                max_sum = curr_sum;
                ans = layer;
            }
        }
        return ans;
    }
};