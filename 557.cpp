// 自己的答案
class Solution {
public:
    string reverseWords(string s) 
    {
        string ans = s;
        int right = 0, left = 0;
        char temp;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]==' ')
            {
                left = i - 1;
                while(right<left)
                {
                    temp = ans[right];
                    ans[right] = ans[left];
                    ans[left] = temp;
                    right ++;
                    left --;
                }
                right = i + 1;
            }
            if(i==ans.size()-1)
            {
                left = i;
                while(right<left)
                {
                    temp = ans[right];
                    ans[right] = ans[left];
                    ans[left] = temp;
                    right ++;
                    left --;
                }
            }
        }  
        return ans;  
    }
};


// method 1
class Solution {
public:
    string reverseWords(string s) {
        string result;
        int lastSpaceIndex = -1;
        for (int strIndex = 0; strIndex < s.length(); strIndex++) {
            if ((strIndex == s.length() - 1) || s[strIndex] == ' ') {
                int reverseStrIndex =
                    (strIndex == s.length() - 1) ? strIndex : strIndex - 1;
                for (; reverseStrIndex > lastSpaceIndex; reverseStrIndex--) {
                    result += s[reverseStrIndex];
                }
                if (strIndex != s.length() - 1) {
                    result += ' ';
                }
                lastSpaceIndex = strIndex;
            }
        }
        return result;
    }
};

//method 2 two pointer
class Solution {
public:
    string reverseWords(string s) {
        int lastSpaceIndex = -1;
        int len = (int)s.size();
        for (int strIndex = 0; strIndex <= len; strIndex++) {
            if (strIndex == len || s[strIndex] == ' ') {
                int startIndex = lastSpaceIndex + 1;
                int endIndex = strIndex - 1;
                while (startIndex < endIndex) {
                    char temp = s[startIndex];
                    s[startIndex] = s[endIndex];
                    s[endIndex] = temp;
                    startIndex++;
                    endIndex--;
                }
                lastSpaceIndex = strIndex;
            }
        }
        return s;
    };
};