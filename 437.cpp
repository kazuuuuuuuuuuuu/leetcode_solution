// 两个递归
class Solution
{
    public:
        int ans = 0;

        int pathSum(TreeNode* root, int sum)
        {
            dfs2(root, sum);
            return ans;
        }

        // 这个递归决定起点
        // 递归调用每一个树中的点
        // 根节点调用dfs 作为起点
        // 左右节点递归调用
        void dfs2(TreeNode* root, int target)
        {
            if(root!=nullptr)
            {
                // apply dfs on the current node
                // and call its children recursively
                dfs(root, target, 0);
                dfs2(root->left, target);
                dfs2(root->right, target);
            }
        }

        // 这个递归计算从起点开始 到本节点的sum值
        // 如果和sum相等就更新ans值
        // 代表有一个合法路径
        void dfs(TreeNode* root, int target, long  curr)
        {
            if(root!=nullptr)
            {
                curr += root->val;
                if(curr==target)
                    ans ++;
                // the updated value (curr)
                dfs(root->left, target, curr);
                dfs(root->right, target, curr);
            }
        }
};