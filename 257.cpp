class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;
        traverse(root, path, ans);
        return ans;
    }

    void traverse(TreeNode* node, vector<int> &path, vector<string> &ans)
    {
        if(node->left==NULL&&node->right==NULL)
        {
            path.push_back(node->val);
            string onepath;
            onepath += to_string(path[0]);
            for(int i=1;i<path.size();i++)
            {
                onepath += "->";
                onepath += to_string(path[i]);
            }
            ans.push_back(onepath);
            path.pop_back();             // 因为用了& 所以要回溯
            return;
        }

        path.push_back(node->val);
        
        if(node->left)
        {
            traverse(node->left, path, ans);
 
        }
        if(node->right)
        {
            traverse(node->right, path, ans);
        }
        path.pop_back();             // 因为用了& 所以要回溯
        
    }
};