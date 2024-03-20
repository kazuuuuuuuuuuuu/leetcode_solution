
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder);
    }
// 从两个数组中建立一颗树 
TreeNode* build(vector<int> inorder, vector<int> postorder)
{
    // exit
    if(postorder.size()==0) return NULL;
    int val = postorder[postorder.size()-1];
    TreeNode* node = new TreeNode(val);    
    if(postorder.size()==1)
    {
        return node;
    }

    // split two vectors
    int i;
    for(i=0;i<inorder.size();i++)
    {
        if(inorder[i]==val)
            break;
    }
    // 左闭 右开生成新的vector
    vector<int> left_inorder(inorder.begin(), inorder.begin()+i);
    vector<int> right_inorder(inorder.begin()+i+1, inorder.begin()+inorder.size());

    vector<int> left_postorder(postorder.begin(), postorder.begin()+left_inorder.size());
    vector<int> right_postorder(postorder.begin()+left_inorder.size(), postorder.begin()+postorder.size()-1);

    node->left = build(left_inorder, left_postorder);
    node->right = build(right_inorder, right_postorder);
    return node;
}    
};

// 通过下标来传递区间

class Solution {
public:
    vector<int> inorder;
    vector<int> postorder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        return build(0, inorder.size()-1, 0, postorder.size()-1);
    }

    // 从两个数组中建立一颗树 
    TreeNode* build(int inorder_i, int inorder_j, int postorder_i, int postorder_j)
    {
        // exit
        if(postorder_i>postorder_j) return NULL;
        int val = postorder[postorder_j];
        TreeNode* node = new TreeNode(val);    
        if(postorder_i==postorder_j)
        {
            return node;
        }

        // split two vectors
        int i;
        for(i=inorder_i;i<=inorder_j;i++)
        {
            if(inorder[i]==val)
                break;
        }

        int left_inorder_i = inorder_i;
        int left_inorder_j = i - 1;
        int length = left_inorder_j - left_inorder_i + 1;
        int left_postorder_i = postorder_i;
        int left_postorder_j = postorder_i + length - 1;

        int right_inorder_i = i + 1;
        int right_inorder_j = inorder_j;
        int right_postorder_i = postorder_i + length;
        int right_postorder_j = postorder_j - 1;

        node->left = build(left_inorder_i, left_inorder_j, left_postorder_i, left_postorder_j);
        node->right = build(right_inorder_i, right_inorder_j, right_postorder_i, right_postorder_j);
        return node;
    }    
};


