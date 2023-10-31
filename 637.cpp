class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        double sum;
        vector<double> ans;
        if(!root)
            return ans;
        queue<TreeNode *> queue;
        queue.push(root);

        while(!queue.empty())
        {
            int length = queue.size();
            sum = 0;
            for(int i=0;i<length;i++)
            {
                TreeNode *curr = queue.front();
                queue.pop();
                sum += curr->val;
                if(curr->left)
                    queue.push(curr->left);
                if(curr->right)
                    queue.push(curr->right);
            }
            ans.push_back(sum/length);
        }
        return ans;
    }
};