// insert into a bst
// 1 find the correct position to insert
// 2 create a node with the value provided

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
            helper(root, val);
            return root;
    }
    // 注意这里是要修改curr->left所指向的内容
    // 如果pass by value
    // 只能修改形参和实参指针所一同指向的内容
    // 但改变形参所指向的位置 并不能改变实参所指向的位置
    // 所以要加引用
    void helper(TreeNode* &curr, int val)
    {
        if(curr==nullptr)
            curr = new TreeNode(val);


        if(curr->val>val)
            helper(curr->left, val);
        if(curr->val<val)
            helper(curr->right, val);
    }
};

// iteration
// 这道题并不需要用栈来实现 因为并不是遍历所有节点
// iteration
TreeNode* insertIntoBST(TreeNode* root, int val)
{
    if(root==nullptr)
    {
        root =  new TreeNode(val);
        return root;
    }
    TreeNode* prev = nullptr;
    TreeNode* curr = root;
    int flag;
    while(curr)
    {
        prev = curr;
        if(curr->val<val)
        {
            flag = 1;
            curr = curr->right;
        }
        // 如果进了上一个if语句 curr 将会被修改 所以要用if else
        // to guarantee that the two situations are mutually exclusive
        //if(curr->val>val)
        else
        {
            flag = 0;    
            curr = curr->left;
        }
    }
    if(flag)
        prev->right = new TreeNode(val);
    else
        prev->left = new TreeNode(val);
    return root;
}

TreeNode* insertIntoBST(TreeNode* root, int val)
{
    if(root==NULL)
    {
        root = new TreeNode(val);
        return root;
    }
    // 改变一下子树的结构 然后重新接回来 左子树重新回到左子树 右子树重新回到右子树
    if(root->val>val)
        root->left = insertIntoBST(root->left, val);
    if(root->val<val)
        root->right = insertIntoBST(root->right, val);
    return root;
}