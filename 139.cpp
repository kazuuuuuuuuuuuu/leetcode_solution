
class Solution {
public:
    unordered_set<string> set;
    vector<string> wordDict;
    string s;
    vector<int> memo;
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        for(string word : wordDict)
        {
            set.insert(word);
        }
        this->wordDict = wordDict;
        this->s = s;
        memo = vector<int> (s.size(), -1);
        
        return dp(0);
    }

    bool dp(int i)
    {
        if(i==s.size())
            return true;

        if(memo[i]!=-1)
            return memo[i];

        bool ans = false;
        // 该状态由下一个状态的集合得来
        for(string word : wordDict)
        {
            int length = word.size();
            if((i+length)<=s.size())
            {
                if(is_valid(i, length)&&dp(i+length))
                {
                    ans = true;
                    break;
                }
            }
        }
        memo[i] = ans;
        return ans;
    }

    bool is_valid(int start, int length)
    {
        string word = s.substr(start, length);
        if(set.find(word)!=set.end())
            return true;
        else return false;
    }
};
