class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    string s;
    vector<vector<string>> partition(string s) 
    {
        this->s = s;
        backtrack(0);
        return ans;
    }

    void backtrack(int startindex)
    {
        if(startindex==s.size()) // 所有可以走到叶子节点的都是答案
        {
            ans.push_back(path);
        }

        string level = "";
        for(int i=startindex;i<s.size();i++)
        {
            level += s[i];
            if(!isvalid(startindex, i))
                continue;
            path.push_back(level);
            backtrack(i+1);
            path.pop_back();


        }
    }

    bool isvalid(int start, int end) // 二元谓词函数
    {
        while(start<end)
        {
            if(s[start]!=s[end])
                return false;
            start ++;
            end --;
        }
        return true;
    }    
};