class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<int> layer;
        if(!root)
            return ans;
        int flag = 1;

        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty())
        {
            layer.clear();
            int size = queue.size();

            for(int i=0;i<size;i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                if(flag)
                    layer.push_back(node->val);
                else
                    layer.push_front(node->val);
                if(node->left)
                    queue.push(node->left);
                if(node->right)
                    queue.push(node->right);
            }

            flag = 1 - flag;
            vector<int> add;
            copy(layer.begin(), layer.end(), back_inserter(add));
            ans.push_back(add);
        }
        return ans;
    }
};