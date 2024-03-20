class Solution {
public:
    // [i, j]
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

    string reverseStr(string s, int k) 
    {
        for(int i=0;i<s.size();i+=2*k) // 以2k为一个周期移动i
        {
            int j = i + k - 1;
            if(j<s.size())
            {
                swap_s(s, i, j);
            }
            else
            {
                swap_s(s, i, s.size()-1);
            }
        }
        return s;
    }
};