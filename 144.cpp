// preoreder traversal
// recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }

    void traverse(TreeNode* curr, vector<int> &ans)
    {
        if(curr!=NULL)
        {
            ans.push_back(curr->val);
            traverse(curr->left, ans);
            traverse(curr->right, ans);
        }
    }
};

// stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root)
            st.push(root);

        while(!st.empty())
        {
            TreeNode* curr = st.top();
            st.pop();

            ans.push_back(curr->val);
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
        }
        return ans;
    }
};

// postorder reversal
// recursion
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;           
    }

    void traverse(TreeNode* curr, vector<int> &ans)
    {
        if(curr!=NULL)
        {
            traverse(curr->left, ans);
            traverse(curr->right, ans);            
            ans.push_back(curr->val);
            
        }
    }      
};

// stack
class Solution {
public:
    // 中 右 左 （前序遍历是中 左 右） ->  reverse -> 左 右 中
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st;
        if(root)
            st.push(root);

        while(!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();

            ans.push_back(curr->val);
            if(curr->left)
                st.push(curr->left);
            if(curr->right)
                st.push(curr->right);
        }

        if(!ans.empty())
            reverse(ans.begin(), ans.end());
        return ans;
    }      
};

// inorder traversal
// recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;        
    }
    void traverse(TreeNode* curr, vector<int> &ans)
    {
        if(curr!=NULL)
        {
            traverse(curr->left, ans);
            ans.push_back(curr->val);
            traverse(curr->right, ans);
        }
    }    
};

// stack -> 左子树都没了开始处理当前节点
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st; // 记录遍历过的节点
        TreeNode *curr = root; // 遍历节点用的指针

        while(curr!=NULL||!st.empty())
        {
            while(curr)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }    
};