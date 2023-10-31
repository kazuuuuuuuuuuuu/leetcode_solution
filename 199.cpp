class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // base case
        vector<int> ans;
        if(!root)
            return ans;

        deque<TreeNode*> deque;
        deque.push_back(root);

        while(!deque.empty())
        {
            int nums_for_layer = deque.size();
            ans.push_back(deque.back()->val);

            for(int i=0;i<nums_for_layer;i++)
            {
                TreeNode* node = deque.front();
                deque.pop_front();

                if(node->left)
                    deque.push_back(node->left);
                if(node->right)
                    deque.push_back(node->right);
            }
        }
        return ans;
    }
};

// queue 也可以实现这个操作
// pop() push() front() back()