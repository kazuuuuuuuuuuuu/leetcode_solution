// brute force -> 每个饼干有k个选项 全部遍历一遍 找符合条件的答案
class Solution {
public:
    vector<int> distribution;
    int n;
    int k;
    vector<int> cookies;

    int distributeCookies(vector<int>& cookies, int k) 
    {
        this->k = k;
        this->cookies = cookies;
        n = cookies.size();
        distribution = vector<int> (k, 0);
        return backtrack(0, 0);
    }

    int backtrack(int layer, int new_child)
    {
        // 所有饼干都被分完了
        if(layer==n)
        {
            int ans = 0;
            for(int &num : distribution)
            {
                ans = max(ans, num);
            }
            return ans;
        }

        int ans = INT_MAX;
        for(int i=0;i<new_child;i++)
        {
            distribution[i] += cookies[layer];
            ans = min(ans, backtrack(layer+1, new_child));
            distribution[i] -= cookies[layer];
        }

        // 新的孩子可以分派饼干 就在原来基础上增加一个人
        if(new_child<k)
        {
            distribution[new_child] += cookies[layer];
            ans = min(ans, backtrack(layer+1, new_child+1));
            distribution[new_child] -= cookies[layer];            
        }
        return ans;
    }
};

