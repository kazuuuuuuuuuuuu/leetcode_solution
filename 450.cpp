class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        search(root, key);
        return root;
    }

    // 查找要删除的目标节点
    // 注意要用引用 因为根节点可能就要被删
    // 如果没有引用 删除除根结点之外的其他节点将会在原指针上操作 而根节点是一个复制后的指针
    // 修改他对原指针没有任何影响
    void search(TreeNode* &root, int key)
    {
        if(root==nullptr)
            return;
        if(root->val==key)
            deletep(root);
        else if(root->val>key)
            search(root->left, key);
        else
            search(root->right, key);
    }

    // 删除
    // 查找到目标节点的指针
    // 直接在原指针上操作 -> 使用引用
    void deletep(TreeNode *&p)
    {
        TreeNode *q = p;
        // 没有右子树 直接拿左孩子替代
        if(p->right==nullptr)
        {
            p = p->left;
            delete q;
        }
        // 没有左子树 直接拿右孩子替代
        else if(p->left==nullptr)
        {
            p =p->right;
            delete q;
        }
        // 两个子树都存在
        // 找到左子树的最右下节点
        else
            delete1(p, p->left);
    }

    void delete1(TreeNode *p, TreeNode *&r)
    {
        if(r->right!=nullptr)
            delete1(p, r->right);
        // 找到后和要删的节点交换值
        // 之后最右下节点没有右子树 直接用左子树替换即可
        else
        {
            TreeNode *q = r;
            p->val = r->val;
            r = r->left;
            delete q;
        }
    }
};

class Solution {
public:
    // 修改子树 然后返回给上一级的节点 用对应的左右子树接住
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        // exit1
        if(root==NULL) return NULL;
        // exit2
        // 通过跳过要删除节点的方式 来删除节点
        if(root->val==key)
        {
            if(root->left==NULL&&root->right==NULL)
                return NULL;
            if((root->left!=NULL&&root->right==NULL))
                return root->left;
            if((root->left==NULL&&root->right!=NULL))
                return root->right;
            else
            {
                TreeNode* curr = root->right;
                while(curr->left)
                {
                    curr = curr->left;
                }
                curr->left = root->left;
                return root->right;
            }
        }
        if(root->val<key)
            root->right = deleteNode(root->right, key);
        if(root->val>key)
            root->left = deleteNode(root->left, key);
        return root;
    }
};

