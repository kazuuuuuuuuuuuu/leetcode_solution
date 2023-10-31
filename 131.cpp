class Solution {
public:
    int n;
    string s;
    vector<vector<string>> partition(string s) 
    {
        this->s = s;
        n = s.size();
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(0, ans, curr);
        return ans;
    }

    // 注意同层 和 递归（下一层对输入参数的改变）
    void backtrack(int start, vector<vector<string>> &ans, vector<string> &curr)
    {
        if(start==n)
        {
            ans.push_back(curr);
            return;
        }
        string level = "";
        for(int i=start;i<n;i++)
        {
            level += s[i];
            if(valid(level))
            {
                curr.push_back(level);
                backtrack(i+1, ans, curr);
                curr.pop_back();
            }
        }

    }

    bool valid(string &str)
    {
        int i = 0;
        int j = str.size()-1;
        while(i<j)
        {
            if(str[i]!=str[j])
                return false;
            i ++;
            j --;
        }
        return true;
    }
};