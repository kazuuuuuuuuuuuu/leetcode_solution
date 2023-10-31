// get all values and sort them 
// to get the minimum absolute difference
// using inorder dps traversal can get all values and sort them

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> sorted_array = helper(root);
        int ans = INT_MAX;

        for(int i=0;i<sorted_array.size()-1;i++)
        {
            // subtracted by the previous one
            int curr = abs(sorted_array[i+1]-sorted_array[i]);
            ans = min(ans, curr);
        }
        return ans;
    }

    vector<int> helper(TreeNode* root)
    {
        if(!root)
            return vector<int>{};
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        left.push_back(root->val);
        left.insert(left.end(),right.begin(), right.end());
        return left;
    }


};

// if you perform an inorder traversal on a bst, you will visit nodes in a sorted order
// iterative version 
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> values = iterativeInorder(root);
        int ans = INT_MAX;
        for (int i = 1; i < values.size(); i++) {
            ans = min(ans, values[i] - values[i - 1]);
        }

        return ans;
    }
    
    vector<int> iterativeInorder(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> values;
        TreeNode* curr = root;
        
        // inorder 左 根 右
        // 抽象出来一种情况
        // 所有的节点都被当作根来处理（在他的左已经被处理之后
        while (!stack.empty() || curr != nullptr) {
            if (curr != nullptr) {
                stack.push(curr);
                curr = curr->left;
            } else {
                curr = stack.top();
                stack.pop();
                values.push_back(curr->val);
                curr = curr->right;
            }
        }

        return values;
    }
};

// if you perform an inorder traversal on a bst, you will visit nodes in a sorted order
// exercise
int getMinimumDifference(TreeNode* root)
{
    vector<int> ans = helper(root);
    int min_dif = INT_MAX;
    for(int i=0;i<ans.size()-1;i++)
    {
        min_dif = min(min_dif, abs(ans[i]-ans[i+1]));
    }
    return min_dif;
}

vector<int> helper(TreeNode* root)
{
    vector<int> ans;
    // using stack to simulate an inorder traversal
    stack<TreeNode*> stack;
    TreeNode* curr = root;

    while(!stack.empty()||curr!=nullptr)
    {
        if(curr!=nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        // 左子树已处理完毕或者为空
        // 所有元素均当作根节点来处理
        else
        {
            curr = stack.top();
            stack.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ans;
}