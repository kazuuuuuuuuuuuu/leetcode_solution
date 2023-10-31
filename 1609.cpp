class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode *> queue;
        queue.push(root);
        int layer = -1;

        while(!queue.empty())
        {
            layer ++;
            int length = queue.size();
            bool first = true;
            int last_val;

            for(int i=0;i<length;i++)
            {
                TreeNode *curr = queue.front();
                queue.pop();

                if(layer%2==0)
                {
                    if(curr->val%2!=1)
                        return false;
                    else
                    {
                        if(first)
                        {
                            first = false;
                            last_val = curr->val;
                        }
                        else
                        {
                            if(curr->val<=last_val)
                                return false;
                            else
                            {
                                last_val = curr->val;
                            }
                        }
                        if(curr->left)
                            queue.push(curr->left);
                        if(curr->right)
                            queue.push(curr->right);
                    }
                }
                else
                {
                    if(curr->val%2!=0)
                        return false;
                    else
                    {
                        if(first)
                        {
                            first = false;
                            last_val = curr->val;
                        }
                        else
                        {
                            if(curr->val>=last_val)
                                return false;
                            else
                            {
                                last_val = curr->val;

                            }
                        }
                        if(curr->left)
                            queue.push(curr->left);
                        if(curr->right)
                            queue.push(curr->right);
                    }
                }
            }
        }
        return true;
    }
};