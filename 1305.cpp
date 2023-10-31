class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> arr1;
        vector<int> arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);

        // 两个有序序列做二路归并
        vector<int> ans(arr1.size()+arr2.size());
        merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), ans.begin());

        return ans;


    }

    // 中序遍历是有序序列
    void inorder(TreeNode* root, vector<int> &arr)
    {
        if(root!=nullptr)
        {
            inorder(root->left);
            arr.push_back(root->val);
            inorder(root->right);
        }
    }
};