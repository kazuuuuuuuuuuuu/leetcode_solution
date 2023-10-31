// 双递归结构
// 一个递归按要求执行逻辑计算
// 另一个递归决定起始位置
class Solution {
public:
    int ans = 0;
    
    int longestZigZag(TreeNode* root) 
    {
        dfs1(root);
        return ans;
    }

    // change the starting position recusively
    void dfs1(TreeNode* root)
    {
        if(root!=nullptr)
        {
            dfs2(root, -1, 0);
            dfs2(root, -1, 1);
            dfs1(root->left);
            dfs1(root->right);
        }
    }

    // execute the logic 
    void dfs2(TreeNode* root, int curr, int direction)
    {
        if(root!=nullptr)
        {
            curr ++;
            if(direction==0)
                dfs2(root->left, curr, 1);
            else
                dfs2(root->right, curr, 0);
        }
        // root == nullptr
        // reach the end of this path
        // update the ans with the length of the path
        else
        {
            ans = max(ans, curr);
        }
    }
};

// 双递归结构可以实现 但是因为在计算中有太多重复 所以会超时
class Solution {
public:
    int ans = 0;
    // 一个索引存在就更新ans 
    int longestZigZag(TreeNode* root) {
        // 第三个参数代表目前的长度
        // 第二个参数用于交替改变方向
        dfs(root->left, 1, 1);
        dfs(root->right, 0, 1);
        return ans;
    }

    void dfs(TreeNode* root, int next_direction, int length) {
        if (root != nullptr) {
            ans = max(ans, length);
            // 从每个位置开始都可以换另一个方向 长度重新计算
            if (next_direction == 0) {
                dfs(root->left, 1, length + 1);
                dfs(root->right, 0, 1);
            } 
            else if(next_direction==1) 
            {
                dfs(root->right, 0, length + 1);
                dfs(root->left, 1, 1);
            }
        }
    }
};