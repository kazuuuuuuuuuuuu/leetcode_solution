// 先找一个词 再找下一个词 state to the next state
// 他下一个词是对的 他就是对的
class Solution {
public:
    unordered_set<string> set;
    string s;
    vector<int> seen;
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        this->s = s;
        seen = vector<int> (s.size(), -1);
        set = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dp(0);
    }

    bool dp(int start)
    {
        if(start==s.size())
            return true;

        if(seen[start]!=-1)
            return seen[start];

        bool ret = false;
        for(int end=start;end<s.size();end++)
        {
            string substring = s.substr(start, end-start+1);
            if(set.find(substring)!=set.end())
            {
                ret = ret || dp(end+1);
            } 
        }
        seen[start] = ret;
        return ret;
    }
};