class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        queue<TreeNode *> queue;
        queue.push(root->left);
        queue.push(root->right);
        while(!queue.empty())
        {
            // a couple of nodes
            // they are in a symmetrical position
            TreeNode *first = queue.front();
            queue.pop();
            TreeNode *second = queue.front();
            queue.pop();

            if(first==nullptr&&second==nullptr)
                continue;
            if(first==nullptr||second==nullptr||first->val!=second->val)
                return false;
            // the children of that two nodes are still in a symmetrical position
            // push them into the queue to check afterwards
            queue.push(first->left);
            queue.push(second->right);
            queue.push(first->right);
            queue.push(second->left);
        }
        return true;
    }
};


//在对称位置的两个点是一对
//这两个点的孩子节点也是一对
//层序遍历 但是并不要记录层数

// dfs分别遍历两个子树 然后比较对应位置是否相同 
class Solution {
public:
    bool compare(TreeNode *left, TreeNode *right)
    {
        if(left==NULL&&right!=NULL)
            return false;
        if(left!=NULL&&right==NULL)
            return false;
        if(left==NULL&&right==NULL)
            return true;
        if(left!=NULL&&right!=NULL&&left->val!=right->val)
            return false;

        bool outside_result = compare(left->left, right->right);
        bool inner_result = compare(left->right, right->left);
        bool result = outside_result&&inner_result;
        return result;
    }

    bool isSymmetric(TreeNode* root) {
        return compare(root->left, root->right);
    }
};