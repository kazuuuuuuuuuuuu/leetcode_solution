
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parents;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        // convert the binary tree to an undirected graph
        // using a dfs function
        dfs(root, nullptr);
        // bfs traversal preparation
        unordered_set<TreeNode*> seen;
        queue<TreeNode*> queue;
        seen.insert(target);
        queue.push(target);
        int distance = 0;

        // 和bfs遍历树是一样的 用一个while loop和一个 for loop(单层)
        // 加上了一个seen的检查 防止无限循环 
        while(!queue.empty()&&distance<k)
        {
            int layer_length = queue.size();
            for(int i=0;i<layer_length;i++)
            {
                TreeNode* node = queue.front();
                queue.pop();
                for(TreeNode* neighbor : {node->left, node->right, parents[node]})
                {
                    if(neighbor!=nullptr&&seen.find(neighbor)==seen.end())
                    {
                        seen.insert(neighbor);
                        queue.push(neighbor);
                    }
                }
            }
            distance ++;
        }

        vector<int> ans;
        while(!queue.empty())
        {
            TreeNode* node = queue.front();
            queue.pop();
            ans.push_back(node->val);
        }
        return ans;
    }

    void dfs(TreeNode* node, TreeNode* parent)
    {
        if(node==nullptr)
            return;
        parents[node] = parent;
        dfs(node->left, node);
        dfs(node->right, node);

    }
};