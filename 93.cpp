// 0 - 255 inclusive without leading zero
class Solution {
public:
    string s;
    vector<string> restoreIpAddresses(string s) 
    {
        this->s = s;
        string curr = "";
        vector<string> ans;
        backtrack(ans, curr, 0, 0);
        return ans;
    }

    // 确定一次dot的位置
    void backtrack(vector<string> &ans, string curr, int dot, int i)
    {
        string block = "";
        // base case
        if(dot==3)
        {
            // 排除几种问题
            // 最后剩下的位数太多
            if(i+3<s.size())
                return;
            // 最后一个都没剩
            if(i==s.size())
                return;
            // 最受剩下的是以0开头的多位数
            if(s[i]=='0'&&i+1<s.size())
                return;

            while(i<s.size())
            {
                block += s[i];
                i ++;
            }
            if(stoi(block)<=255)
            {
                curr += block;
                ans.push_back(curr);
            }
            return;
        }

        if(s[i]=='0')
        {
            curr += s[i];
            curr += '.';
            i ++;
            backtrack(ans, curr, dot+1, i);
            // 同层没有其他元素不需要回溯
        }
        else
        {
            while(i<s.size()&&stoi(block+s[i])<=255)
            {
                // 这三个变化同层共享 并且其他层之间没有&符号 不会做修改 不需要回溯
                block += s[i];
                curr += s[i];
                i ++;

                curr += '.';
                backtrack(ans, curr, dot+1, i);
                // 同层有其他元素需要回溯
                curr.pop_back();
            } 
        }
    }
};
