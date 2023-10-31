class Solution {
public:
    deque<int> curr;
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, 0);
        return ans;
    }

    // need to use the backtracking funtion during the recursion
    void dfs(TreeNode* root, int targetSum, int currSum)
    {
        // 两个递归出口
        // handle nullptr case
        if(root==nullptr)
            return;

        // adjust the sum and the deque
        currSum += root->val;
        curr.push_back(root->val);       
        
        // the end of the path
        if(root->left==nullptr&&root->right==nullptr)
        {
            if(currSum==targetSum)
            {
                vector<int> path(curr.begin(), curr.end());
                ans.push_back(path);
            }
            curr.pop_back();
            return;
        }

        // explore the left and right subtree
        dfs(root->left, targetSum, currSum);
        dfs(root->right, targetSum, currSum);

        //重点在回溯
        // backtracking
        curr.pop_back(); 
    }
};