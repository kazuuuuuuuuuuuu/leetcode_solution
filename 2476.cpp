class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) 
    {
        vector<vector<int>> ans;
        for(int query : queries)
        {
            int min = -1;
            int max = -1;
            boundary(root, min, max, query);
            vector<int> boundary;
            boundary.push_back(min);
            boundary.push_back(max);
            ans.push_back(boundary);
        }
        return ans;
    }

    // 二叉树本身就是binary search 但是仍然会超时
    // 可能是指针操作涉及很多内存上的读取
    // 该函数修改界限, 正确但是会超时
    void boundary(TreeNode* &node, int &min, int &max, int val)
    {
        if(node==nullptr)
            return;

        if(node->val==val)
        {
            min = val;
            max = val;
            return;
        }

        if(val>node->val)
        {
            min = node->val;
            boundary(node->right, min, max, val);
        }
        else
        {
            max = node->val;
            boundary(node->left, min, max, val);
        }
    }

    // 非递归算法 正确但是也会超时

    void boundary(TreeNode* &node, int &min, int &max, int val)
    {
        TreeNode* nodeptr = node;
        while(nodeptr!=nullptr)
        {
            if(nodeptr->val==val)
            {
                min = val;
                max = val;
                break;
            }
            else if(nodeptr->val>val)
            {
                max = nodeptr->val;
                nodeptr = nodeptr->left;
            }
            else
            {
                min = nodeptr->val;
                nodeptr = nodeptr->right;
            }
        }
    }

};

// 方法2 利用中序遍历二叉搜索树是有序的数列
// 之后在这个序列使用二分查找 binary search
class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) 
    {
        vector<vector<int>> ans;
        vector<int> array;
        dfs(root, array);

        for(int query : queries)
        {
            int min = min1(array, query);
            int max = max1(array, query);
            ans.push_back({min, max});
        }
        return ans;
    }

    void dfs(TreeNode* node, vector<int> &array)
    {
        if(node==nullptr)
            return;
        //  left mid right
        dfs(node->left, array);
        array.push_back(node->val);
        dfs(node->right, array);
    }

    int min1(vector<int> &array, int val)
    {
        int left = 0;
        int right = array.size()-1;
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(array[mid]<=val)
                left = mid + 1;
            else
                right = mid - 1;

        }
        if(right>=0&&right<=array.size()-1)
            return array[right];
        else 
            return -1;
    }

    int max1(vector<int> &array, int val)
    {
        int left = 0;
        int right = array.size()-1;
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(array[mid]<val)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if(left>=0&&left<=array.size()-1)
            return array[left];
        else 
            return -1;
    }
};