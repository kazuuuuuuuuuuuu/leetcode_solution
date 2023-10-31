// once the problem is about layers
// the first thing should come in mind is bfs

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty())
        {
            int size = queue.size();
            int max_ = 0x80000000;

            for(int i=0;i<size;i++)
            {
                TreeNode *node= queue.front();
                queue.pop();
                max_ = max(max_, node->val);
                if(node->left)
                    queue.push(node->left);
                if(node->right)
                    queue.push(node->right);
            }
            ans.push_back(max_);
        }
        return ans;
    }
};