class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> layer;
        vector<vector<int>> ans;
        if(!root)
            return ans;

        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty())
        {
            int length = queue.size();
            layer.clear();
            for(int i=0;i<length;i++)
            {
                TreeNode* curr = queue.front();
                queue.pop();

                layer.push_back(curr->val);
                if(curr->left)
                    queue.push(curr->left);
                if(curr->right)
                    queue.push(curr->right);
            }
            ans.push_back(layer);
        }
        return ans;
    }
};