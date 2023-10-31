// using dfs postorder traversal to get the value of leaves 
// and add them into a vector
// then check if the vector is the same 
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> sequence1;
        vector<int> sequence2;
        dfs(root1, sequence1);
        dfs(root2, sequence2);
        if(sequence1.size()!=sequence2.size())
            return false;
        int n = sequence1.size();
        for(int i=0;i<n;i++)
        {
            if(sequence1[i]!=sequence2[i])
                return false;
        }
        return true;
    }

    void dfs(TreeNode* root, vector<int>& sequence)
    {
        if(root!=nullptr)
        {        
            dfs(root->left, sequence);
            dfs(root->right, sequence);
            if(root->left==nullptr&&root->right==nullptr)
            {
                sequence.push_back(root->val);
            }
        }
    } 
};