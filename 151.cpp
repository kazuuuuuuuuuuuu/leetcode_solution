// using stack to reverse 
class Solution {
public:
    string reverseWords(string s) {
        stack<string> stack;
        string word;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ')
                continue;
            word += s[i];
            if(i + 1 == s.size() || s[i + 1] == ' ') {
                stack.push(word);
                word = "";
            }
        }
        string ans;
        while(!stack.empty()) { // 使用 empty() 函数检查栈是否为空
            word = stack.top(); // 使用 top() 函数获取栈顶元素
            stack.pop(); // 使用 pop() 函数弹出栈顶元素
            ans += word;
            ans += ' ';
        }
        if(!ans.empty()) // 检查 ans 是否为空，避免尝试从空字符串中访问元素
            ans = string(ans.begin(), ans.end() - 1); // 去除最后一个额外的空格
        return ans;
    }
};

class Solution {
public:
    void swap_s(string &s, int i, int j)
    {
        while(i<j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i ++;
            j --;
        }
    }

    string reverseWords(string s) 
    {
        // 1 remove the redundent spaces using two pointes 
        int slow = 0;
        for(int fast=0;fast<s.size();fast++)
        {
            if(s[fast]==' ')
                continue;
            if(slow!=0)
            {
                s[slow] = ' ';
                slow ++;                
            }
            while(fast<s.size()&&s[fast]!=' ')
            {
                s[slow] = s[fast];
                slow ++;
                fast ++;
            }
        }
        s.resize(slow);

        // 2 reverse the whole string
        reverse(s.begin(), s.end());

        // 3 reverse each word
        int start = 0;
        for(int i=0;i<s.size();i++)
        {
            if(i==s.size()-1||s[i+1]==' ')
            {
                swap_s(s, start, i);
                start = i + 2;
            }
        }
        return s;
    }
};