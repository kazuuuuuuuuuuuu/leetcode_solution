// 双指针

class Solution {
public:
    int appendCharacters(string s, string t) 
    {
        int i = 0;
        int j = 0;
        int ans = 0;
        int s_length = s.size();
        int t_length = t.size();

        while(i<s_length&&j<t_length)
        {
            if(s[i]==t[j])
            {
                i ++;
                j ++;
            }
            else
                i ++;
        }
        ans = t_length - j;
        return ans;
    }
};